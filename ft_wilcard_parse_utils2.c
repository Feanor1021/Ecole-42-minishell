/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wilcard_parse_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:38:30 by akarabay          #+#    #+#             */
/*   Updated: 2022/09/09 14:43:30 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static void	db_stars(t_command *command, int i, int j, int size)
{
	char	**tmp;
	char	*needle;

	needle = ft_only_word(command->arguments[1]);
	while (command->arguments[++i])
		if (ft_strstr(command->arguments[i], needle))
			size++;
	tmp = ft_calloc(sizeof(char *), size + 3);
	tmp[0] = command->arguments[0];
	tmp[1] = command->arguments[1];
	i = 1;
	while (command->arguments[++i])
	{
		if (ft_strstr(command->arguments[i], needle))
			tmp[++j] = command->arguments[i];
		else
			free(command->arguments[i]);
	}
	free(command->arguments);
	command->arguments = tmp;
	free(needle);
}

static void	left_star(t_command *cmd, int i, int j, int size)
{
	char	**tmp;
	char	*needle;

	needle = ft_only_word(cmd->arguments[1]);
	while (cmd->arguments[++i])
		if (ft_strstr_last(cmd->arguments[i], needle) && \
			ft_strstr_last(cmd->arguments[i], needle) \
			[ft_strlen(needle)] == '\0')
			size++;
	tmp = ft_calloc(sizeof(char *), size + 3);
	tmp[0] = cmd->arguments[0];
	tmp[1] = cmd->arguments[1];
	i = 1;
	while (cmd->arguments[++i])
	{
		if (ft_strstr_last(cmd->arguments[i], needle) && \
			ft_strstr_last(cmd->arguments[i], needle) \
			[ft_strlen(needle)] == '\0')
			tmp[++j] = cmd->arguments[i];
		else
			free(cmd->arguments[i]);
	}
	free(cmd->arguments);
	cmd->arguments = tmp;
	free(needle);
}

static void	right_star(t_command *command, int i, int j, int size)
{
	char	**tmp;
	char	*needle;

	needle = ft_only_word(command->arguments[1]);
	while (command->arguments[++i])
	{
		if (ft_strstr(command->arguments[i], needle) == command->arguments[i])
			size++;
	}
	tmp = ft_calloc(sizeof(char *), size + 3);
	tmp[0] = command->arguments[0];
	tmp[1] = command->arguments[1];
	i = 1;
	while (command->arguments[++i])
	{
		if (ft_strstr(command->arguments[i], needle) == command->arguments[i])
			tmp[++j] = command->arguments[i];
		else
			free(command->arguments[i]);
	}
	free(command->arguments);
	command->arguments = tmp;
	free(needle);
}

static void	db_wildcard(t_command *command, char **s)
{
	char	*tmp;

	tmp = command->arguments[1];
	command->arguments[1] = s[0];
	if (tmp[0] == '*')
		db_stars(command, 1, 1, 0);
	else
		right_star(command, 1, 1, 0);
	command->arguments[1] = s[1];
	if (tmp[ft_strlen(tmp) - 1] == '*')
		ft_db_stars_secondpart(command, 1, 1, s[0]);
	else
		ft_left_star_secondpart(command, 1, 1, s[0]);
	command->arguments[1] = tmp;
	ft_freearr_str(s);
}

int	ft_acheck(t_command *command)
{
	int		star_mod;
	int		total_words;

	ft_opendir(command);
	total_words = ft_total_words(command->arguments[1], 0, 0);
	if (total_words > 1)
		db_wildcard(command, ft_split(command->arguments[1], '*'));
	else
	{
		star_mod = ft_star_state(command->arguments[1]);
		if (star_mod == DB_STARS)
			db_stars(command, 1, 1, 0);
		else if (star_mod == LEFT_STAR)
			left_star(command, 1, 1, 0);
		else if (star_mod == RIGHT_STAR)
			right_star(command, 1, 1, 0);
	}
	ft_arrfix(command);
	return (0);
}
