/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initsubshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:30:32 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/21 13:23:41 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "42-Libft/libft.h"

static void	helper(t_command *cmd)
{
	if (ft_arrlen((void **)cmd->redirections) > 0)
	{
		ft_connectio(cmd);
		ft_closepipes();
		ft_runpipelines(cmd->subshells);
	}
	else
	{
		ft_runpipelines(cmd->subshells);
		ft_closepipes();
	}
}

int	ft_initsubshell(t_command *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		g_mini->issubshell = 1;
		ft_clearsignals();
		if (!ft_open_reds(cmd))
		{
			g_mini->exitflag = 1;
			exit(-1);
		}
		helper(cmd);
		g_mini->exitflag = 1;
		exit(-1);
	}
	return (pid);
}
