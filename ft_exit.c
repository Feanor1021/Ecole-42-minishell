/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:19:34 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:46:32 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_exit(t_command *cmd)
{
	(void)cmd;
	g_mini->exitflag = 1;
	if (!g_mini->issubshell && cmd->in == 0 && cmd->out == 1)
		ft_putendl_fd("exit", 2);
	if (cmd->arguments[1])
	{
		if (ft_isnumeric(cmd->arguments[1]))
			return (ft_atoi(cmd->arguments[1]));
		else
		{
			ft_putstr_fd("bash: exit :", 2);
			ft_putstr_fd(cmd->arguments[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
			return (255);
		}
	}
	return (0);
}
