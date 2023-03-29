/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:15:38 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:15:42 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_reg_file(char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return ((((path_stat.st_mode) & S_IFMT) == S_IFREG));
}

static char	*join_path(char *path, char *file)
{
	char	*p;
	int		i;

	i = 0;
	p = ft_calloc(sizeof(char), ft_strlen(path) + ft_strlen(file) + 2);
	while (*path)
		p[i++] = *path++;
	if (p[i - 1] != '/')
		p[i++] = '/';
	while (*file)
		p[i++] = *file++;
	return (p);
}

int	is_file_exist(char *path)
{
	if (path && access(path, F_OK) == 0)
		return (1);
	return (0);
}

char	*find_in_path(char *file)
{
	char	**paths;
	char	*path;
	int		i;

	if (is_path(file))
		return (ft_strdup(file));
	paths = ft_split(get_env("PATH"), ':');
	i = 0;
	while (paths[i])
	{
		path = join_path(paths[i++], file);
		if (is_file_exist(path))
			break ;
		free(path);
		path = NULL;
	}
	ft_free_arr_str(paths);
	return (path);
}
