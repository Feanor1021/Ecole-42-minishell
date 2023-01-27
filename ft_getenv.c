/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:58:46 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:54:09 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

char	*ft_getenv(char *name)
{
	int		i;
	int		variable_index;
	char	*var;

	variable_index = ft_getenvindex(name);
	if (variable_index == -1)
		return (NULL);
	var = g_mini->env[variable_index];
	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	if (var[i])
		i++;
	return (var + i);
}
