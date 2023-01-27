/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsepipelines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:03:09 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:56:00 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "42-Libft/libft.h"

static void	*erroroccured(t_pipeline **pipes, t_token *token)
{
	ft_freearr_pipeline(pipes);
	if (token)
		ft_syntaxerror(token);
	return (NULL);
}

static void	checkcondition(t_token **tokens, int start, \
				t_pipeline **pipes, int lastpipe)
{
	if (lastpipe > 0)
	{
		if (tokens[start]->type == AND)
			pipes[lastpipe]->dependon = DEP_AND;
		else if (tokens[start]->type == OR)
			pipes[lastpipe]->dependon = DEP_OR;
	}
}

static t_pipeline	*parsepipeline(t_token **tokens, int start, int end)
{
	t_pipeline	*ret;

	if ((tokens[0]->data[0] == '|' ) || \
	(tokens[0]->data[0] == '|' && tokens[0]->data[1] == '|') | \
	(tokens[0]->data[0] == '&' && tokens[0]->data[1] == '&'))
	{
		ft_syntaxerror(*tokens);
		return (NULL);
	}
	if (ft_islogic(tokens[start]))
		start++;
	ret = ft_calloc(sizeof(t_pipeline), 1);
	ret->commands = ft_parsecommands(tokens, start, end);
	if (!ret->commands)
	{
		ft_freearr_command(ret->commands);
		free(ret);
		return (NULL);
	}
	return (ret);
}

static int	findend(t_token **tokens, int start, int end)
{
	if (tokens[start]->type == LPAR)
		start = ft_skipbrackets(tokens, start, end);
	if (start == -1)
		return (-1);
	while (start < end && tokens[start] && !ft_islogic(tokens[start]))
	{
		if (tokens[start]->type == LPAR)
			start = ft_skipbrackets(tokens, start, end);
		else
			start++;
	}
	return (start);
}

t_pipeline	**ft_parsepipelines(t_token **tokens, int start, int end)
{
	t_pipeline	*pipeline;
	t_pipeline	**pipes;
	int			lastpipe;
	int			i;

	lastpipe = -1;
	pipes = NULL;
	i = start;
	while (i < end)
	{
		i = findend(tokens, i, end);
		if (i == -1)
			return (erroroccured(pipes, NULL));
		pipeline = parsepipeline(tokens, start, i);
		if (tokens[i] && ft_islogic(tokens[i]))
			if (!tokens[++i])
				return (erroroccured(pipes, tokens[i - 1]));
		if (!pipeline)
			return (erroroccured(pipes, NULL));
		ft_addarr_pipeline(&pipes, pipeline);
		checkcondition(tokens, start, pipes, ++lastpipe);
		start = i - 1;
	}
	return (pipes);
}
