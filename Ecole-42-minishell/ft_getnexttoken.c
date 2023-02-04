/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnexttoken.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:19:33 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:53:47 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static t_token	*onechartoken(char *str, int *i)
{
	if (str[*i] == '|')
		return (ft_getonechartoken(PIPE, i, '|'));
	else if (str[*i] == '>')
		return (ft_getonechartoken(RED_CREATE, i, '>'));
	else if (str[*i] == '<')
		return (ft_getonechartoken(RED_INPUT, i, '<'));
	else if (str[*i] == '(')
		return (ft_getonechartoken(LPAR, i, '('));
	else if (str[*i] == ')')
		return (ft_getonechartoken(RPAR, i, ')'));
	return (NULL);
}

static t_token	*twochartoken(char *str, int *i)
{
	if (str[*i] == '|' && str[*i + 1] == '|')
		return (ft_gettwochartoken(str, i, OR, '|'));
	else if (str[*i] == '&' && str[*i + 1] == '&')
		return (ft_gettwochartoken(str, i, AND, '&'));
	else if (str[*i] == '>' && str[*i + 1] == '>')
		return (ft_gettwochartoken(str, i, RED_APPEND, '>'));
	else if (str[*i] == '<' && str[*i + 1] == '<')
		return (ft_gettwochartoken(str, i, HEREDOC, '<'));
	return (NULL);
}

t_token	*ft_getnexttoken(char *str)
{
	static int	i = 0;
	t_token		*token;

	token = NULL;
	while (str[i])
	{
		token = twochartoken(str, &i);
		if (token)
			break ;
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
