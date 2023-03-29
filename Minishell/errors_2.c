/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:11:10 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:56:42 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_error_ln(char *msg, char *data)
{
	ft_putstr_fd("bash: ", 2);
	if (data)
	{
		ft_putstr_fd(data, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(msg, 2);
}

void	ft_add_arr_stream(t_stream ***arr, t_stream *new)
{
	ft_add_arr((void ***)arr, (void *)new);
}

void	ft_add_arr_pipeline(t_pipeline ***arr, t_pipeline *new)
{
	ft_add_arr((void ***)arr, (void *)new);
}
