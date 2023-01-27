/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenvindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:14:29 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:53:51 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_getenvindex(char *name)
{
	int		i;
	int		k;
	int		index;
	char	**env;

	if (name[0] == '$')
		name++;
	index = 0;
	env = g_mini->env;
	while (env[index])
	{
		i = 0;
		k = 0;
		while (env[index][i] && env[index][i] == name[k])
		{
			i++;
			k++;
		}
		if ((!name[k] && env[index][i] == '=') || !env[index][i])
			return (index);
		index++;
	}
	return (-1);
}
