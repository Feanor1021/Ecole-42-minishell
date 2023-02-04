/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettwochartoken.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:40:58 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:53:37 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "42-Libft/libft.h"

t_token	*ft_gettwochartoken(char *str, int *i, enum e_tokentype type, char chr)
{
	char	schr[3];

	(*i)++;
	if (str[*i] == chr)
	{
		schr[0] = chr;
		schr[1] = chr;
		schr[2] = 0;
		(*i)++;
		return (ft_createtoken(ft_strdup(schr), type));
	}
	return (NULL);
}
