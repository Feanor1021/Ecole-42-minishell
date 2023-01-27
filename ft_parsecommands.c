/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecommands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:03:24 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:55:52 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static void	*erroroccured(t_command **commands, t_token *token)
{
	ft_freearr_command(commands);
	if (token)
		ft_syntaxerror(token);
	return (NULL);
}

t_command	**ft_parsecommands(t_token **tokens, int start, int end)
{
	t_command	*cmd;
	t_command	**commands;
	int			i;

	commands = NULL;
	i = start;
	while (i < end)
	{
		if (tokens[start]->type == LPAR)
			i = ft_skipbrackets(tokens, start, end);
		if (i == -1)
			return (erroroccured(commands, NULL));
		while (i < end && tokens[i] && tokens[i]->type != PIPE)
			i++;
		cmd = ft_parsecommand(tokens, start, i);
		if (!cmd)
			return (erroroccured(commands, NULL));
		ft_addarr_command(&commands, cmd);
		if (tokens[i] && tokens[i]->type == PIPE)
			if (!tokens[++i])
				return (erroroccured(commands, tokens[i - 1]));
		start = i;
	}
	return (commands);
}
