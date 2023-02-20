/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:18:22 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/17 14:19:52 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	printf("%d\n%d\n%d\n%d\n%d\n", ft_isascii(32),\
	 ft_isascii(73), ft_isascii(94), ft_isascii(140), ft_isascii(949));
}
*/