/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:22:25 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:22:31 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell		*g_shell;

static void	init_g_shell(char **env)
{
	g_shell = ft_calloc(sizeof(t_shell), 1);
	g_shell->env = ft_copyarr_str(env);
}

static void	miniloop(void)
{
	char	*input;

	while (!g_shell->e_flag)
	{
		input = ft_getinput();
		if (!input)
		{
			write(1, "exit\n", 5);
			break ;
		}
		ft_execline(input);
		free(input);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	exitcode;

	(void)argv;
	(void)argc;
	(void)exitcode;
	init_g_shell(env);
	ft_connectsignals();
	if (argc == 1)
		miniloop();
	exitcode = g_shell->return_code;
	ft_free_arr_str(g_shell->env);
	free(g_shell);
	return (exitcode);
}
