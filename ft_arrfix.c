/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:40:30 by akarabay          #+#    #+#             */
/*   Updated: 2022/09/09 14:43:56 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static void	dot_check(t_command *command)
{
	int		index;
	int		len;
	char	**tmp;

	if (command->arguments[1] && command->arguments[1][0] == '.')
		return ;
	index = 2;
	while (command->arguments[index] && command->arguments[index][0] == '.')
		index++;
	len = 0;
	while (command->arguments[index++])
		len++;
	tmp = ft_calloc(sizeof(char *), len + 3);
	index = -1;
	len = 0;
	while (command->arguments[++index])
	{
		if (command->arguments[index][0] != '.')
			tmp[len++] = command->arguments[index];
		else
			free(command->arguments[index]);
	}
	free(command->arguments);
	command->arguments = tmp;
}

void	ft_arrfix(t_command *cmd)
{
	int		index;
	int		len;
	char	*tmp_arg1;
	char	**tmp;

	if (ft_strchr(cmd->arguments[1], '*') && !cmd->arguments[2])
		return ;
	dot_check(cmd);
	index = 1;
	len = ft_arrlen((void **)cmd->arguments);
	if (len == 2)
		cmd->arguments[1] = 0;
	else
	{
		tmp = ft_calloc(sizeof(char *), len);
		tmp[0] = cmd->arguments[0];
		tmp_arg1 = cmd->arguments[1];
		while (cmd->arguments[++index])
			tmp[index - 1] = cmd->arguments[index];
		free(cmd->arguments);
		free(tmp_arg1);
		cmd->arguments = tmp;
	}
}
