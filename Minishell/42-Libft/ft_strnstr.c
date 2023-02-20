/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:38:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/11 18:44:49 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	i = 0;
	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	while (haystack[i] && needle_len <= len)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
		len--;
	}
	return (NULL);
}

/*char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t poz;
	char *res;
	size_t i;
	size_t a;

	poz = ft_strlen((char *)haystack);
	res = (char *)haystack;
	i = 0;
	a = 0;
	if(ft_strlen(needle) == 0)
		return(res);

	while(res[i] != '\0' && len >= ft_strlen(needle))
	{
		while (res[i + a] == needle[a] && res[i + a] != '\0' && needle[a] != '\0')
			a++;
		if(needle[a] == '\0')
			return(&res[i]);
		i++;
		len--;
	}
	return(NULL);
}
*/
/*
int main()
{
	char	samanlık[] = "ahmet";
	char	igne[] = "";
	
	printf("%s\n", ft_strnstr(samanlık, igne , 7));
	printf("%s", strnstr(samanlık, igne , 7));
}
*/