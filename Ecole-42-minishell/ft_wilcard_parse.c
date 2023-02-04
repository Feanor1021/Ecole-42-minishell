/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wilcard_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:07:52 by akarabay          #+#    #+#             */
/*   Updated: 2022/09/12 23:27:58 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static int	total_star(t_command *command)
{
	int	index;
	int	len;

	index = 1;
	len = 0;
	while (command->arguments[index])
	{
		if (ft_strchr(command->arguments[index], '*'))
		{
			len++;
			index++;
		}
		else
		{
			len++;
			while (command->arguments[index] && \
			ft_strchr(command->arguments[index], '*') == 0)
				index++;
		}
	}
	return (len);
}

static void	normal_words(char ***arr, char **arg, int *index, int t_index)
{
	int	len;

	len = 0;
	while (arg[*index + len] && !ft_strchr(arg[*index + len], '*'))
		len++;
	arr[t_index] = ft_calloc(sizeof(char *), len + 2);
	arr[t_index][0] = arg[0];
	len = 1;
	while (arg[*index] && !ft_strchr(arg[*index], '*'))
		arr[t_index][len++] = arg[(*index)++];
	(*index)--;
}

static int	__last_step(char ***arr, char *command)
{
	int	index;
	int	t_index;
	int	len;

	len = 0;
	index = -1;
	while (arr[++index])
	{
		t_index = -1;
		while (arr[index][++t_index])
		{
			if (ft_strcmp(arr[index][t_index], command))
				len++;
		}
	}
	return (len);
}

static void	last_step(char ***arr, char *command, t_command *cmd, int f_index)
{
	int		index;
	int		t_index;
	char	**cmd_tmp;
	int		len;

	len = __last_step(arr, command);
	cmd_tmp = ft_calloc(sizeof(char *), len + 2);
	cmd_tmp[0] = command;
	index = -1;
	while (arr[++index])
	{
		t_index = -1;
		while (arr[index][++t_index])
		{
			if (ft_strcmp(arr[index][t_index], command))
				cmd_tmp[f_index++] = arr[index][t_index];
		}
	}
	cmd->arguments = cmd_tmp;
	index = -1;
	while (arr[++index])
		free(arr[index]);
	free(arr);
}

int	ft_parse_wildcard(t_command *command, int index, int t_index)
{
	t_wildcard	wildcard;

	if (!ft_check_star(command))
		return (0);
	wildcard.len = total_star(command);
	wildcard.tmp = ft_calloc(sizeof(char **), wildcard.len + 1);
	wildcard.tmp2 = command->arguments;
	while (wildcard.tmp2[++index])
	{
		if (ft_strchr(wildcard.tmp2[index], '*'))
		{
			wildcard.tmp[t_index] = ft_calloc(sizeof(char *), 3);
			command->arguments = wildcard.tmp[t_index++];
			command->arguments[0] = wildcard.tmp2[0];
			command->arguments[1] = wildcard.tmp2[index];
			ft_acheck(command);
			wildcard.tmp[t_index -1] = command->arguments;
		}
		else
			normal_words(wildcard.tmp, wildcard.tmp2, &index, t_index++);
	}
	last_step(wildcard.tmp, wildcard.tmp2[0], command, 1);
	free(wildcard.tmp2);
	return (0);
}
