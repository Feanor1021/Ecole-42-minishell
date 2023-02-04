/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:32:57 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/20 15:11:33 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	ft_execline(char *input)
{
	t_token		**tokens;
	t_pipeline	**pipelines;

	tokens = ft_gettokens(input);
	pipelines = NULL;
	if (tokens)
	{
		pipelines = ft_parsepipelines(tokens, 0, ft_arrlen((void **)tokens));
		if (pipelines)
		{
			ft_runpipelines(pipelines);
			ft_freearr_pipeline(pipelines);
		}
		ft_freearr_token(tokens);
	}
}
