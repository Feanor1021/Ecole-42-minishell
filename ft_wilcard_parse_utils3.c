/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wilcard_parse_utils3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:38:23 by akarabay          #+#    #+#             */
/*   Updated: 2022/09/09 14:44:30 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static char	**_helper(t_command *cmd, int *size)
{
	char	**tmp;

	tmp = ft_calloc(sizeof(char *), *size + 2);
	tmp[0] = cmd->arguments[0];
	tmp[1] = cmd->arguments[1];
	*size = 1;
	return (tmp);
}

char	*ft_revstrstr(char *haystack, char *needle)
{
	int	index;
	int	t_index;

	if (!*needle)
		return (haystack);
	index = 0;
	while (haystack[index])
	{
		t_index = 0;
		while (haystack[index + t_index] == needle[t_index] && needle[t_index])
			t_index++;
		if (!needle[t_index])
			return (haystack + index + t_index);
		index++;
	}
	return (NULL);
}

void	ft_db_stars_secondpart(t_command *command, int i, int j, char *fs)
{
	char	**tmp;
	char	*needle;

	needle = command->arguments[1];
	while (command->arguments[++i])
		if (ft_strstr(ft_revstrstr(command->arguments[i], fs), needle))
			j++;
	tmp = _helper(command, &j);
	i = 1;
	while (command->arguments[++i])
	{
		if (ft_strstr(ft_revstrstr(command->arguments[i], fs), needle))
			tmp[++j] = command->arguments[i];
		else
			free(command->arguments[i]);
	}
	free(command->arguments);
	command->arguments = tmp;
}

void	ft_left_star_secondpart(t_command *cmd, int i, int j, char *fs)
{
	char	**tmp;
	char	*needle;

	needle = cmd->arguments[1];
	while (cmd->arguments[++i])
	{
		if (ft_strstr_last(ft_revstrstr(cmd->arguments[i], fs), needle) && \
			ft_strstr_last(ft_revstrstr(cmd->arguments[i], fs), needle) \
			[ft_strlen(needle)] == '\0')
			j++;
	}
	tmp = _helper(cmd, &j);
	i = 1;
	while (cmd->arguments[++i])
	{
		if (ft_strstr_last(ft_revstrstr(cmd->arguments[i], fs), needle) && \
			ft_strstr_last(ft_revstrstr(cmd->arguments[i], fs), needle) \
			[ft_strlen(needle)] == '\0')
			tmp[++j] = cmd->arguments[i];
		else
			free(cmd->arguments[i]);
	}
	free(cmd->arguments);
	cmd->arguments = tmp;
}
