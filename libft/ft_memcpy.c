/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:28:11 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:28:12 by fyardimc         ###   ########.fr       */
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
