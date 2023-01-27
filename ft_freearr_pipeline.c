/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 07:25:47 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:47:10 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freearr_pipeline(t_pipeline **pipes)
{
	ft_freearr((void **)pipes, (void (*)(void *))ft_freepipeline);
}
