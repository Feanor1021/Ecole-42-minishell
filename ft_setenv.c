/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:41:29 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:48:53 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"
#include "42-Libft/libft.h"

static void	only_key(char *name)
{
	if (ft_getenvindex(name) == -1)
		ft_addarr_str(&(g_mini->env), ft_strdup(name));
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

void	ft_setenv(char *name, char *value)
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
	i = ft_getenvindex(name);
	if (i != -1)
	{
		free(g_mini->env[i]);
		g_mini->env[i] = var;
	}
	else
		ft_addarr_str(&(g_mini->env), var);
	free(name);
	free(value);
}
