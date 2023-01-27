/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:57:27 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:46:24 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_check(char *s)
{
	int	i;

	i = 0;
	if (!ft_isalpha_underscore(s[i++]))
		return (0);
	while (s[i] && s[i] != '=')
	{
		if (!ft_is_env(s[i++]))
			return (0);
	}
	return (1);
}
