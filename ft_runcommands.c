/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runcommands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:29:38 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:49:07 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_runcommands(t_command **cmds)
{
	int		i;
	pid_t	lastcommand;

	i = 0;
	g_mini->intflag = 1;
	while (cmds[i])
		if (!ft_heredoc(cmds[i++]))
			return (0);
	ft_connectpipes(cmds);
	i = 0;
	while (cmds[i])
		lastcommand = ft_runcommand(cmds[i++]);
	ft_closepipes();
	if (lastcommand != -1)
	{
		waitpid(lastcommand, &(g_mini->return_code), 0);
		g_mini->return_code = (((g_mini->return_code) & 0xff00) >> 8);
	}
	while (wait(NULL) != -1)
		continue ;
	g_mini->intflag = 0;
	return (1);
}
