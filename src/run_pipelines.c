/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipelines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:25:14 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:25:21 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_runpipelines(t_pipeline *pipes)
{
	g_shell->i_flag = 1;
	if (!get_heredoc(pipes))
		return ;
	if (pipes)
		run_commands(pipes->commands);
	g_shell->i_flag = 0;
}
