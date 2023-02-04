/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:01:13 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:47:19 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void	ft_freearr(void **arr, void (*f)(void *))
{
	int	i;

	i = 0;
	while (arr && arr[i])
		f(arr[i++]);
	free(arr);
}
