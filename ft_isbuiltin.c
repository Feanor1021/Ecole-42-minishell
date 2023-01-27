/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:25:56 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:52:59 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_isbuiltin(char *command)
{
	if (ft_strcmp(BT_ECHO, command) == 0 || \
		ft_strcmp(BT_CD, command) == 0 || \
		ft_strcmp(BT_PWD, command) == 0 || \
		ft_strcmp(BT_EXIT, command) == 0 || \
		ft_strcmp(BT_EXPORT, command) == 0 || \
		ft_strcmp(BT_UNSET, command) == 0 || \
		ft_strcmp(BT_ENV, command) == 0)
		return (1);
	return (0);
}
