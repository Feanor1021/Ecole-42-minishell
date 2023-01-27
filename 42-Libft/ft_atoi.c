/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:38:31 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/13 20:22:20 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		s;
	long	res;

	s = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || \
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		if (res * s < -2147483648)
			return (0);
		else if (res * s > 2147483647)
			return (-1);
		str++;
	}
	return (res * s);
}

/*
int main()
{
	char str[] = "  ----+123";
	printf("%d", ft_atoi(str));
}
*/