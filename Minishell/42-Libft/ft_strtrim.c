/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:52:41 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/15 14:43:32 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
size_t ft_strlen(const char *s)
{
    int i;
    i = 0;
    while(s[i])
    {
        i++;
    }
    return (i);
}

char *ft_strdup(const char *s1)
{
    size_t len = ft_strlen(s1) +1;
    void *new = malloc(len);

    if (new == NULL)
    return(NULL);

    return((char*) memcpy(new, s1, len));
}

char *ft_strchr(const char *s, int c)
{
    while(*s != 0)
    {
        if(*s == c)
        {
            return((char*)s);
        }
        s++;
    }
    if(c == 0)
        return((char *)s);
    return(0);
}
 
char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *dest;
    size_t    index;

    if (!s)
        return (0);
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
*/
/*
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	if ((int)(i - (int)s1 + 1) <= 0)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, 0, i + 1));
}*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
