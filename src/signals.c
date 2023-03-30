/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:25:25 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:25:34 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signalhandler(int sig)
{
	(void)sig;
	if (g_shell->i_flag)
	{
		printf("\n");
		g_shell->i_flag = 0;
		return ;
	}
	g_shell->return_code = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_connectsignals(void)
{
	signal(SIGINT, ft_signalhandler);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_clearsignals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
