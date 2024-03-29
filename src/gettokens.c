/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:46:27 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 17:55:39 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	getwordlen(char *str, int *i)
{
	int	len;

	len = 0;
	while (!ft_isdelimitter(str[*i + len]) && str[*i + len])
	{
		if (ft_isquote(str[*i + (len)]))
		{
			len++;
			while (str[*i + len] && !ft_isquote(str[*i + len]))
				len++;
			if (ft_isquote(str[*i + len]))
				len++;
		}
		else
			len++;
	}
	*i += len;
	return (len);
}

static t_token	*ft_getwordtoken(char *str, int *i)
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
		{
			data[k] = str[j];
			k++;
			j++;
		}
		return (ft_createtoken(data, WORD));
	}
	return (NULL);
}

static t_token	*ft_getnexttoken(char *str)
{
	static int	i;
	t_token		*token;

	token = NULL;
	while (str[i])
	{
		token = onechartoken(str, &i);
		if (token)
			break ;
		if (!ft_isdelimitter(str[i]))
			return (ft_getwordtoken(str, &i));
		else
			i++;
	}
	if (token)
		return (token);
	i = 0;
	return (NULL);
}

t_token	**ft_gettokens(char *str)
{
	t_token	**tokens;
	t_token	*token;

	tokens = NULL;
	while (1)
	{
		token = ft_getnexttoken(str);
		if (!token)
			break ;
		ft_add_arr_token(&tokens, token);
	}
	return (tokens);
}
