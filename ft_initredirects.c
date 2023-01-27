/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initredirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:32:43 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/02 20:23:17 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_initredirects(t_command *cmd)
{
	if (ft_open_reds(cmd))
	{
		g_mini->return_code = 0;
		return (-1);
	}
	g_mini->return_code = 1;
	return (0);
}
