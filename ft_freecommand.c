/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freecommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:55:59 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:47:24 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

void	ft_freecommand(t_command *cmd)
{
	if (cmd)
	{
		if (cmd->out != 1)
			close(cmd->out);
		if (cmd->in != 0)
			close(cmd->in);
		ft_freearr_str(cmd->arguments);
		ft_freearr_str(cmd->heredocsteps);
		ft_freearr((void **)cmd->redirections, (void (*)(void *))ft_freestream);
		ft_freearr_pipeline(cmd->subshells);
		free(cmd->command);
		free(cmd);
	}
}
