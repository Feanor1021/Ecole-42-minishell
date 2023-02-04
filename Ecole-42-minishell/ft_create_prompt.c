/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:36:08 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:46:05 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"

char	*ft_create_prompt(void)
{
	char		*prompt;
	char		*cwd;
	int			len;

	cwd = "minishell % ";
	len = ft_strlen(cwd);
	prompt = ft_calloc(sizeof(char), len + 1);
	ft_memmove(prompt, cwd, len);
	return (prompt);
}
