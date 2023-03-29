/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:11:58 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:11:59 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execline(char *input)
{
	t_token		**tokens;
	t_pipeline	*pipelines;

	tokens = ft_gettokens(input);
	pipelines = NULL;
	if (tokens)
	{
		pipelines = ft_parsepipelines(tokens, 0, ft_arrlen((void **)tokens));
		if (pipelines)
		{
			ft_runpipelines(pipelines);
			ft_free_pipeline(pipelines);
		}
		ft_free_arr_token(tokens);
	}
}
