/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:24:57 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 17:43:47 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_errors(t_command *cmd, char *path)
{
	if (is_file_exist(path))
	{
		put_error_ln("is a directory", cmd->command);
		g_shell->return_code = 126;
	}
	else
	{
		g_shell->return_code = 127;
		put_error_ln("No such file or directory", cmd->command);
	}
}

char	*path_controller(t_command *cmd, char *cmdpath)
{
	if (get_env_index("PATH") != -1 || cmd->command[0] == '/')
		return (cmdpath = find_in_path(cmd->command));
	return (NULL);
}

static int	exec_process(t_command *cmd)
{
	char	*cmdpath;
	pid_t	pid;

	cmdpath = NULL;
	if (!cmd->command)
	{
		open_redirs(cmd);
		return (-1);
	}
	cmdpath = path_controller(cmd, cmdpath);
	pid = -1;
	if (cmdpath)
	{
		if (is_reg_file(cmdpath))
			pid = init_process(cmd, cmdpath);
		else
			check_errors(cmd, cmdpath);
	}
	else
	{
		put_error_ln("commad not found", cmd->command);
		g_shell->return_code = 127;
	}
	free(cmdpath);
	return (pid);
}

int	ft_runcommand(t_command *cmd)
{
	pid_t	pid;

	ft_pars_quote(cmd);
	if (is_built_in(cmd->command))
		pid = init_built_in(cmd);
	else if (!cmd->command)
		pid = init_redirects(cmd);
	else
		pid = exec_process(cmd);
	return (pid);
}

void	run_commands(t_command **cmds)
{
	int		i;
	pid_t	last_command;

	i = 0;
	ft_connect_pipes(cmds);
	while (cmds[i] && !g_shell->e_flag)
		last_command = ft_runcommand(cmds[i++]);
	ft_close_pipes();
	if (last_command != -1)
	{
		waitpid(last_command, &(g_shell->return_code), 0);
		g_shell->return_code = (((g_shell->return_code) & 0xff00) >> 8);
	}
	while (wait(NULL) != -1)
		continue ;
}
