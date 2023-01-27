/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runcommand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:05:08 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/09 15:10:18 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "minishell.h"
#include "42-Libft/libft.h"

static void	checkerrors(t_command *cmd, char *path)
{
	if (ft_filexists(path))
	{
		ft_puterrln("is a directory", cmd->command);
		g_mini->return_code = 126;
	}
	else
	{
		g_mini->return_code = 127;
		ft_puterrln("No such file or directory", cmd->command);
	}
}

char	*ft_path_controler(t_command *cmd, char *cmdpath)
{
	if (ft_getenvindex("PATH") != -1 || cmd->command[0] == '/')
		return (cmdpath = ft_findinpath(cmd->command));
	return (NULL);
}

static int	execprocess(t_command *cmd)
{
	char	*cmdpath;
	pid_t	pid;

	cmdpath = NULL;
	if (!cmd->command)
	{
		ft_open_reds(cmd);
		return (-1);
	}
	cmdpath = ft_path_controler(cmd, cmdpath);
	pid = -1;
	if (cmdpath)
	{
		if (ft_isfile(cmdpath))
			pid = ft_initprocess(cmd, cmdpath);
		else
			checkerrors(cmd, cmdpath);
	}
	else
	{
		ft_puterrln("command not found", cmd->command);
		g_mini->return_code = 127;
	}
	free(cmdpath);
	return (pid);
}

int	ft_runcommand(t_command *cmd)
{
	pid_t	pid;

	ft_parse_wildcard(cmd, 0, 0);
	ft_pars_quote(cmd);
	if (cmd->subshells)
		pid = ft_initsubshell(cmd);
	else if (ft_isbuiltin(cmd->command))
		pid = ft_initbuiltin(cmd);
	else if (!cmd->command)
		pid = ft_initredirects(cmd);
	else
		pid = execprocess(cmd);
	return (pid);
}
