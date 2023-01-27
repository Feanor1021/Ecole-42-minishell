/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyarr_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:02:06 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:46:02 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

char	**ft_copyarr_str(char **arr)
{
	char	**ret;
	int		i;

	ret = ft_calloc(sizeof(char *), ft_arrlen((void **)arr) + 1);
	i = 0;
	while (arr && *arr)
		ret[i++] = ft_strdup(*arr++);
	return (ret);
}
