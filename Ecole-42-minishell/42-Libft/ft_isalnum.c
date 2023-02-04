/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:57:57 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/17 14:12:15 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || \
	(c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*
int	main(void)
{
	printf("%d\n%d\n%d\n", ft_isalnum('a'), ft_isalnum('S'), ft_isalnum('3'));
}
*/
