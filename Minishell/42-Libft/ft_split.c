/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:28:36 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:28:37 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	wordsize(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != 0)
	{
		if (*s == c)
			s++;
		else
		{
			i++;
			while (*s != '\0' && *s != c)
				s++;
		}	
	}
	return (i);
}

char	**ft_free(char **s, size_t index)
{
	while (s[index] != 0 && index)
	{
		free(s[index]);
		s[index] = NULL;
		index--;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	size_t	index;
	size_t	size;

	word = (char **)malloc(sizeof(char *) * (wordsize(s, c) + 1));
	if (!word || !s)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			size = 0;
			while (*(s + size) && *(s + size) != c)
			size++;
			word[index++] = ft_substr(s, 0, size);
			if (index < wordsize(s, c) && !(word))
				return (ft_free(word, index));
			s += size;
		}
	}
	word[index] = 0;
	return (word);
}
