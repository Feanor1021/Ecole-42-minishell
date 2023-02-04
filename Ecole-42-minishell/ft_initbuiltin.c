/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initbuiltin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:29:37 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/21 13:23:41 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_initbuiltin(t_command *cmd)
{
	pid_t	pid;

	if (cmd->in != 0 || cmd->out != 1)
	{
		pid = fork();
		if (pid == 0)
		{
			g_mini->exitflag = 1;
			if (!ft_open_reds(cmd))
				exit(-1);
			g_mini->return_code = ft_runbuiltin(cmd);
			ft_closepipes();
			exit(-1);
		}
		return (pid);
	}
	if (!ft_open_reds(cmd))
		return (-1);
	g_mini->return_code = ft_runbuiltin(cmd);
	return (-1);
}
