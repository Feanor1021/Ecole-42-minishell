/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterrno.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:00:13 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:51:20 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "minishell.h"
#include "42-Libft/libft.h"

void	ft_puterrno(void)
{
	char	*msg;

	msg = strerror(errno);
	ft_putstr_fd(msg, 2);
}
