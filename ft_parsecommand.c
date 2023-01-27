/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecommand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:02:21 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:54:58 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static void	*erroroccured(t_command *cmd)
{
	ft_freecommand(cmd);
	return (NULL);
}

static t_command	*createcommand(void)
{
	t_command	*cmd;

	cmd = ft_calloc(sizeof(t_command), 1);
	cmd->in = 0;
	cmd->out = 1;
	return (cmd);
}

int	parsetoken(t_token **tokens, int *start, int end, t_command *cmd)
{
	if (tokens[*start]->type == LPAR && \
		!ft_parsesubshell(cmd, tokens, start, end))
		return (0);
	else if (*start < end && tokens[*start]->type == RPAR)
	{
		ft_syntaxerror(tokens[*start]);
		return (0);
	}
	else if (*start < end && tokens[*start]->type == WORD && \
			!ft_parsewordtoken(cmd, tokens, *start))
		return (0);
	else if (*start < end && tokens[*start]->type == HEREDOC && \
			!ft_parseheredoc(cmd, tokens, start))
		return (0);
	else if (*start < end && tokens[*start]->type == RED_INPUT && \
			!ft_parseredinput(cmd, tokens, start))
		return (0);
	else if (*start < end && \
			(tokens[*start]->type == RED_CREATE || \
			tokens[*start]->type == RED_APPEND))
		if (!ft_parseredoutput(cmd, tokens, start))
			return (0);
	return (1);
}

t_command	*ft_parsecommand(t_token **tokens, int start, int end)
{
	t_command	*cmd;

	cmd = createcommand();
	while (tokens[start] && start < end)
	{	
		if (!parsetoken(tokens, &start, end, cmd))
			return (erroroccured(cmd));
		start++;
	}
	return (cmd);
}
