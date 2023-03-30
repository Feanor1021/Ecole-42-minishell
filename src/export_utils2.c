/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:15:18 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:55:11 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	only_key(char *name)
{
	if (get_env_index(name) == -1)
		ft_add_arr_str(&(g_shell->env), ft_strdup(name));
}

static int	__setenv(char *name, char *value)
{
	if (!value)
	{
		only_key(name);
		return (0);
	}
	return (1);
}

void	set_env(char *name, char *value)
{
	char	*var;
	int		i;
	int		namelen;
	int		valuelen;

	if (!__setenv(name, value))
		return ;
	namelen = ft_strlen(name);
	valuelen = ft_strlen(value);
	var = ft_calloc(sizeof(char), namelen + valuelen + 2);
	ft_memcpy(var, name, namelen);
	var[namelen] = '=';
	ft_memcpy(var + namelen + 1, value, valuelen);
	i = get_env_index(name);
	if (i != -1)
	{
		free(g_shell->env[i]);
		g_shell->env[i] = var;
	}
	else
		ft_add_arr_str(&(g_shell->env), var);
	free(name);
	free(value);
}
