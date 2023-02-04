/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwordtoken.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:25:33 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:53:29 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static int	getwordlen(char *str, int *i)
{
	int		len;
	char	block;

	len = 0;
	while (str[*i + len])
	{
		if (ft_isquote(str[*i + len]))
		{
			block = str[*i + (len++)];
			while (str[*i + len] && str[*i + len] != block)
				len++;
			if (str[*i + len] == block)
				len++;
		}
		else if (ft_isdelimitter(str[*i + len]) || \
				(str[*i + len] == '&' && str[*i + len + 1] == '&'))
			break ;
		else
			len++;
	}
	*i += len;
	return (len);
}

t_token	*ft_getwordtoken(char *str, int *i)
{
	char	*data;
	int		j;
	int		k;

	j = *i;
	if (!ft_isdelimitter(str[*i]))
	{
		data = ft_calloc(sizeof(char), getwordlen(str, i) + 1);
		k = 0;
		while (j != *i)
			data[k++] = str[j++];
		return (ft_createtoken(data, WORD));
	}
	return (NULL);
}
