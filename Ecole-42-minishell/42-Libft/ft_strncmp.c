/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:38:41 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/12 18:29:12 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	index = 0;
	if (n == 0)
		return (n);
	while (s1[index] && s2[index] && s1[index] == s2[index] && index < n)	
	{
		index++;
		return (0);
	}
	return(((unsigned char) s1[index]) - ((unsigned char) s2[index]));
}*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index] && index < n)
		index++;
	if (index == n)
		return (0);
	return (((unsigned char) s1[index]) - ((unsigned char) s2[index]));
}
