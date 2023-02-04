/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 08:32:46 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:48:13 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42-Libft/libft.h"

void	ft_strappend(char **str, char *appendstr)
{
	char	*old;

	if (!appendstr)
		return ;
	old = *str;
	*str = ft_strjoin(*str, appendstr);
	free(old);
}
