/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:20:12 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:49:15 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"
#include "42-Libft/libft.h"

static int	new_str_len(char *str, char *a, char *b, char *target)
{
	int	len;
	int	i;
	int	k;

	len = 0;
	while (str + len != target)
		len++;
	i = 0;
	k = len;
	while (str[k] == a[i])
	{
		k++;
		i++;
	}
	len += ft_strlen(str + k);
	len += ft_strlen(b);
	return (len);
}

static char	*replace_str(char *str, char *a, char *b, char *target)
{
	char	*ret;
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	ret = ft_calloc(sizeof(char), new_str_len(str, a, b, target) + 2);
	while (str + len != target)
		ret[j++] = str[len++];
	while (str[len] && a[i] && str[len] == a[i])
	{
		len++;
		i++;
	}
	k = 0;
	while (b[k])
		ret[j++] = b[k++];
	while (str[len])
		ret[j++] = str[len++];
	free(str);
	return (ret);
}

void	ft_replace(char **str, char *a, char *b)
{
	char	*target;
	int		len_a;
	int		len_str;
	
	(void)len_a;
	(void)len_str;
	len_a = ft_strlen(a);
	len_str = ft_strlen(*str);
	target = ft_strnstr(*str, a, ft_strlen(*str));
	if (b && target)
	{
		*str = replace_str(*str, a, b, target);
		target = ft_strnstr(*str, a, ft_strlen(*str));
	}
	else if (!b)
	{
		ft_strnstr(*str, a, ft_strlen(*str));
		ft_memmove(ft_strnstr(*str, a, ft_strlen(*str)), \
		ft_strnstr(*str, a, ft_strlen(*str)) + ft_strlen(a), ft_strlen(*str));
	}
}
