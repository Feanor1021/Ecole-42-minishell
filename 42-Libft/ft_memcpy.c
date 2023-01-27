/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:23:59 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/17 13:52:10 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	if (dest == src || !n)
		return (dest);
	index = 0;
	while (index < n)
	{
		*((char *)dest + index) = *((char *)src + index);
		index++;
	}
	return (dest);
}
