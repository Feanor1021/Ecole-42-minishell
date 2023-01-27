/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addarr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:45:35 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:44:23 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"

void	ft_addarr_int(int **arr, int len, int new)
{
	int	*newarr;

	newarr = ft_calloc(sizeof(int), len + 1);
	if (*arr)
		ft_memcpy(newarr, *arr, sizeof(int) * len);
	newarr[len] = new;
	free(*arr);
	*arr = newarr;
}
