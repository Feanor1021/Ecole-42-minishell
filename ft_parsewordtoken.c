/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsewordtoken.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:42:27 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:51:32 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_parsewordtoken(t_command *cmd, t_token **tokens, int i)
{
	if (cmd->subshells)
	{
		ft_syntaxerror(tokens[i]);
		return (0);
	}
	if (!cmd->command)
		cmd->command = ft_strdup(tokens[i]->data);
	ft_addarr_str(&(cmd->arguments), ft_strdup(tokens[i]->data));
	return (1);
}
