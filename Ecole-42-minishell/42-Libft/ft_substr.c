/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:30:12 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/17 14:03:00 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	index;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(*s) * (len + 1));
	if (!dest)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	index = 0;
	while (len--)
		dest[index++] = s[start++];
	dest[index] = '\0';
	return (dest);
}

/*
int main()
{
	printf("%s", ft_substr("Mehmet Eren Akbulut", 6, 6));
	printf("%d", substr("Mehmet Eren Akbulut", 6, 6));
	return (0);
}
*/
