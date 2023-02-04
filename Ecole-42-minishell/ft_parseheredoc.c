/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseheredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:41:19 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:55:56 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_parseheredoc(t_command *cmd, t_token **tokens, int *i)
{
	(*i)++;
	if (tokens[*i] && tokens[*i]->type == WORD)
	{
		ft_addarr_str(&(cmd->heredocsteps), ft_strdup(tokens[*i]->data));
		return (1);
	}
	ft_syntaxerror(tokens[*i]);
	return (0);
}
