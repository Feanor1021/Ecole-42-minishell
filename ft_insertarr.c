/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:50:28 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:53:19 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "42-Libft/libft.h"

void	ft_insertarr(void ***arr, void *new, int index)
{
	void	**newarr;
	int		i;
	int		k;

	newarr = ft_calloc(sizeof(void *), ft_arrlen((void **)*arr) + 2);
	i = 0;
	k = 0;
	while (*arr && (*arr)[k])
	{
		if (k == index)
			newarr[i++] = new;
		newarr[i++] = (*arr)[k];
		k++;
	}
	free(*arr);
	*arr = newarr;
}
