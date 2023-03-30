/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:27:05 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:31:02 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	buffer = (void *) malloc(size * nmemb);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, size * nmemb);
	return (buffer);
}
