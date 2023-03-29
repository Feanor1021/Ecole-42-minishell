/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:21:57 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:46:29 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	connect_io(t_command *cmd)
{
	if (cmd->out != 1)
	{
		dup2(cmd->out, 1);
		close(cmd->out);
		cmd->out = 1;
	}
	if (cmd->in != 0)
	{
		dup2(cmd->in, 0);
		close(cmd->in);
		cmd->in = 0;
	}
}

int	init_process(t_command *cmd, char *cmdpath)
{
	int		exec_return;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		ft_clearsignals();
		if (!open_redirs(cmd))
		{
			g_shell->e_flag = 1;
			exit(-1);
		}
		connect_io(cmd);
		ft_close_pipes();
		exec_return = execve(cmdpath, cmd->arguments, g_shell->env);
		if (exec_return != 0)
		{
			put_errno_msg(cmd->command);
			g_shell->e_flag = 1;
			exit(-1);
		}
	}
	return (pid);
}
