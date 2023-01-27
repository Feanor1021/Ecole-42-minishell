/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:10:54 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:52:47 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"

int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
