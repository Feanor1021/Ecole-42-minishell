/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsepipelines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:24:42 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:24:54 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipeline	*ft_parsepipelines(t_token **tokens, int start, int end)
{
	t_pipeline	*pipes;

	if ((char)tokens[0]->data[0] == '|')
	{
		ft_syntaxerror(*tokens);
		return (NULL);
	}
	pipes = ft_calloc(sizeof(t_pipeline), 1);
	if (!pipes)
		return (NULL);
	pipes->commands = ft_parsecommands(tokens, start, end);
	if (!pipes->commands)
	{
		ft_free_arr_command(pipes->commands);
		free(pipes);
		return (NULL);
	}
	if (!pipes)
		return (error_pipeline(pipes, NULL));
	return (pipes);
}
