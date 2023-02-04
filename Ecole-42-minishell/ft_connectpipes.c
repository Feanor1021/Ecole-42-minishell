/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connectpipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 07:53:25 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:45:55 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "minishell.h"

static void	connect_pipe(t_command **cmds, int i, int *p)
{
	if (cmds[i + 1] && i - 1 >= 0)
	{
		ft_addarr_int(&(g_mini->openedpipes), g_mini->pipecount++, p[0]);
		cmds[i]->in = p[0];
		pipe(p);
		cmds[i]->out = p[1];
		ft_addarr_int(&(g_mini->openedpipes), g_mini->pipecount++, p[1]);
	}
	else if (i == 0 && cmds[i + 1])
	{
		pipe(p);
		ft_addarr_int(&(g_mini->openedpipes), g_mini->pipecount++, p[1]);
		cmds[i]->out = p[1];
	}
	else if (!cmds[i + 1])
	{
		cmds[i]->in = p[0];
		ft_addarr_int(&(g_mini->openedpipes), g_mini->pipecount++, p[0]);
	}
}

static void	connectsubshells(t_command *cmd, t_pipeline **subshells)
{
	int	k;
	int	len;

	k = 0;
	while (subshells && subshells[k])
	{
		len = ft_arrlen((void **)subshells[k]->commands);
		if (len > 0)
		{
			subshells[k]->commands[0]->in = cmd->in;
			subshells[k]->commands[len - 1]->out = cmd->out;
		}
		k++;
	}
}

void	ft_connectpipes(t_command **cmds)
{
	int	p[2];
	int	i;
	int	len;

	i = -1;
	len = ft_arrlen((void **)cmds);
	if (len == 1)
		return ;
	while (++i < len)
		connect_pipe(cmds, i, p);
	i = -1;
	while (++i < len)
		connectsubshells(cmds[i], cmds[i]->subshells);
}
