/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extendarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:23:30 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:46:39 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"
#include <stdlib.h>

void	ft_extendarr(void ***arr, void **otherarr)
{
	void	**newarr;
	int		i;
	int		k;

	newarr = ft_calloc(sizeof(void *), \
					ft_arrlen(*arr) + ft_arrlen(otherarr) + 1);
	i = 0;
	k = 0;
	while ((*arr)[k])
		newarr[i++] = (*arr)[k++];
	k = 0;
	while (otherarr[k])
		newarr[i++] = otherarr[k++];
	free(*arr);
	*arr = newarr;
}
