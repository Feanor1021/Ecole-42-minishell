/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:29:22 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:29:23 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*found;

	c = (unsigned char)c;
	if (c == 0)
		return (ft_strchr(s, '\0'));
	found = 0;
	while (ft_strchr(s, c) != 0)
	{
		found = ft_strchr(s, c);
		s = ft_strchr(s, c) + 1;
	}
	return ((char *)found);
}
