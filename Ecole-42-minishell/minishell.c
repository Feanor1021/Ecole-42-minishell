/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:27:14 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/12 23:35:20 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "minishell.h"
#include "42-Libft/libft.h"

t_mini	*g_mini;

static void	init_g_mini(char **env)
{
	g_mini = ft_calloc(sizeof(t_mini), 1);
	g_mini->env = ft_copyarr_str(env);
}

static void	miniloop(void)
{
	char		*input;

	while (!g_mini->exitflag)
	{
		input = ft_getinput();
		if (!input)
			break ;
		ft_execline(input);
		free(input);
	}
}

////////////////////
//      Main
////////////////////
int	main(int ac, char **av, char **env)
{
	int		exitcode;

	(void)av;
	init_g_mini(env);
	ft_connectsignals();
	if (ac == 1)
		miniloop();
	exitcode = g_mini->return_code;
	ft_freearr_str(g_mini->env);
	free(g_mini);
	return (exitcode);
}
