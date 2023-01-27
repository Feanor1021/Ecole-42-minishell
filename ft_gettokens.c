/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:32:54 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:53:40 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "42-Libft/libft.h"

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
		ft_addarr_token(&tokens, token);
	}
	return (tokens);
}
