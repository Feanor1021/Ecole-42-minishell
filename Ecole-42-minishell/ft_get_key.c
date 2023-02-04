/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:46:00 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:47:48 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"
#include "minishell.h"

char	*ft_get_key(char *s)
{
	int		len;
	char	*key;

	len = ft_strlenchr(s, '=');
	key = ft_substr(s, 0, len);
	return (key);
}
