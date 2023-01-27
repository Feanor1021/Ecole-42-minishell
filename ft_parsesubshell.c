/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesubshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:39:04 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:51:42 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static int	checkreds(t_command *cmd, t_token **tokens, int *start)
{
	if (ft_arrlen((void **)cmd->redirections) > 0)
	{
		ft_syntaxerror(tokens[*start]);
		return (0);
	}
	if (ft_arrlen((void **)cmd->heredocsteps) > 0)
	{
		ft_heredoc(cmd);
		ft_syntaxerror(tokens[*start]);
		return (0);
	}
	return (1);
}

int	ft_parsesubshell(t_command *cmd, t_token **tokens, \
							int *start, int end)
{
	int	i;

	if (!checkreds(cmd, tokens, start))
		return (0);
	i = ft_skipbrackets(tokens, *start, end);
	if (i == -1)
		return (0);
	(*start)++;
	i--;
	if (cmd->command || *start == i || cmd->subshells)
	{
		ft_syntaxerror(tokens[*start]);
		return (0);
	}
	cmd->subshells = ft_parsepipelines(tokens, *start, i);
	if (!cmd->subshells)
		return (0);
	cmd->command = ft_strdup("SUBSHELL");
	cmd->arguments = ft_calloc(sizeof(char *), 1);
	*start = i + 1;
	return (1);
}
