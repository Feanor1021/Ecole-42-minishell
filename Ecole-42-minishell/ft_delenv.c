/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:40:08 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:46:16 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

void	ft_delenv(char *name)
{
	int		i;
	int		j;
	int		index_of_variable;
	int		len_of_env;
	char	**new_env;

	index_of_variable = ft_getenvindex(name);
	if (index_of_variable == -1)
		return ;
	len_of_env = ft_arrlen((void **)g_mini->env);
	new_env = ft_calloc(sizeof(char *), len_of_env);
	i = -1;
	j = 0;
	while (g_mini->env[++i])
	{
		if (i == index_of_variable)
			j++;
		new_env[i] = g_mini->env[i + j];
	}
	free(g_mini->env[index_of_variable]);
	free(g_mini->env);
	g_mini->env = new_env;
}
