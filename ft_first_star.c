/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:33:41 by akarabay          #+#    #+#             */
/*   Updated: 2022/09/09 14:34:53 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_first_star(t_command *command)
{
	char	**new_command;
	char	**tmp;

	tmp = command->arguments;
	new_command = ft_calloc(sizeof(char *), 3);
	new_command[0] = "";
	new_command[1] = command->arguments[0];
	command->arguments = new_command;
	ft_acheck(command);
	tmp[0] = command->arguments[1];
	free(command->arguments);
	command->arguments = tmp;
	free(command->command);
	command->command = ft_strdup(command->arguments[0]);
	return (0);
}
