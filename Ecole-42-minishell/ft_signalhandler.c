/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signalhandler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:53:54 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/07 18:31:43 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <signal.h>
#include "minishell.h"
#include "42-Libft/libft.h"

void	ft_signalhandler(int sig)
{
	(void)sig;
	if (g_mini->intflag)
	{
		printf("\n");
		g_mini->intflag = 0;
		return ;
	}
	g_mini->return_code = 1;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}
