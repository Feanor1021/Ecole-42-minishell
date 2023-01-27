/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:31:39 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/21 13:23:41 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_initprocess(t_command *cmd, char *cmdpath)
{
	pid_t	pid;
	int		execreturn;

	pid = fork();
	if (pid == 0)
	{
		ft_clearsignals();
		if (!ft_open_reds(cmd))
		{
			g_mini->exitflag = 1;
			exit(-1);
		}
		ft_connectio(cmd);
		ft_closepipes();
		execreturn = execve(cmdpath, cmd->arguments, g_mini->env);
		if (execreturn != 0)
		{
			ft_puterrno_msg(cmd->command);
			g_mini->exitflag = 1;
			exit(-1);
		}
	}
	return (pid);
}
