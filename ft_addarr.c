/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:03:51 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:44:44 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

void	ft_addarr(void ***arr, void *new)
{
	void	**ret;
	int		i;
	int		k;

	ret = ft_calloc(sizeof(void *), ft_arrlen((void **)*arr) + 2);
	k = 0;
	i = 0;
	while (*arr && (*arr)[k])
		ret[i++] = (*arr)[k++];
	ret[i] = new;
	free(*arr);
	*arr = ret;
}
