/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:53:13 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:54:38 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

char	*ft_getinput(void)
{
	char	*input;
	char	*prompt;

	prompt = ft_create_prompt();
	input = readline(prompt);
	if (input && *input)
		add_history(input);
	free(prompt);
	return (input);
}
