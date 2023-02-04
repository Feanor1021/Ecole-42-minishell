/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipbrackets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:40:25 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:48:16 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_skipbrackets(t_token **tokens, int start, int end)
{
	int	i;

	if (tokens[start] && tokens[start]->type == LPAR)
		start++;
	i = start;
	while (i < end && tokens[i] && tokens[i]->type != RPAR)
	{
		if (tokens[i]->type == LPAR)
		{
			i = ft_skipbrackets(tokens, i, end);
			if (i == -1)
				return (-1);
		}
		else
			i++;
	}
	if (!tokens[i])
	{
		ft_syntaxerror(tokens[i - 1]);
		return (-1);
	}
	return (i + 1);
}
