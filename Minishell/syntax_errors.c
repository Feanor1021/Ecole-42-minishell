/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:25:43 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:25:51 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_syntaxerror(t_token *token)
{
	if (token)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `", 2);
		ft_putstr_fd(token->data, 2);
		ft_putstr_fd("'\n", 2);
	}
	else
		ft_putstr_fd("bash: sytax error near unexpected token `newline'\n", 2);
	g_shell->return_code = 258;
}
