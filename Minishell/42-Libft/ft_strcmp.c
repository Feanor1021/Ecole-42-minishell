/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:58:31 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 20:59:04 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	if (str1 && str2)
	{
		while (*str1 && *str2 && *str1 == *str2)
		{
			str1++;
			str2++;
		}
		return (*str1 - *str2);
	}
	return (1);
}
