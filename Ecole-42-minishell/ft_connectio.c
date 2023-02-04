/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connectio.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:34:02 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/20 15:11:32 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "minishell.h"

void	ft_connectio(t_command *cmd)
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
