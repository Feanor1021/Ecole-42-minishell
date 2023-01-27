/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createtoken.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:16:35 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:46:09 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

t_token	*ft_createtoken(char *data, enum e_tokentype type)
{
	t_token	*token;

	token = ft_calloc(sizeof(t_token), 1);
	token->data = data;
	token->type = type;
	return (token);
}
