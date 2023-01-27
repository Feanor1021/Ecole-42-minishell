/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getonechartoken.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:12:52 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:53:43 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "42-Libft/libft.h"

t_token	*ft_getonechartoken(enum e_tokentype type, int *i, char chr)
{
	char	schr[2];

	(*i)++;
	schr[0] = chr;
	schr[1] = 0;
	return (ft_createtoken(ft_strdup(schr), type));
}
