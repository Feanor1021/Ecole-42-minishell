/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:38:06 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/12 18:28:15 by makbulut         ###   ########.fr       */
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
/*
int main()
{
	char a[9];
	printf("%p", ft_strrchr(a, 'l'));
}
*/