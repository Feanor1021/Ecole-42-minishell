/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runbuiltin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:28:51 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:49:22 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_runbuiltin(t_command *cmd)
{
	if (ft_strcmp(BT_CD, cmd->command) == 0)
		return (ft_cd(cmd));
	else if (ft_strcmp(BT_EXIT, cmd->command) == 0)
		return (ft_exit(cmd));
	else if (ft_strcmp(BT_EXPORT, cmd->command) == 0)
		return (ft_export(cmd));
	else if (ft_strcmp(BT_UNSET, cmd->command) == 0)
		return (ft_unset(cmd));
	else if (ft_strcmp(BT_ENV, cmd->command) == 0)
		return (ft_env(cmd));
	else if (ft_strcmp(BT_ECHO, cmd->command) == 0)
		return (ft_echo(cmd));
	else if (ft_strcmp(BT_PWD, cmd->command) == 0)
		return (ft_pwd(cmd));
	return (127);
}
