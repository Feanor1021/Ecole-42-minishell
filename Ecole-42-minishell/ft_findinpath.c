/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findinpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:10:18 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:46:52 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"
#include "42-Libft/libft.h"

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

char	*ft_findinpath(char *file)
{
	char	**paths;
	char	*path;
	int		i;

	if (ft_ispath(file))
		return (ft_strdup(file));
	paths = ft_split(ft_getenv("PATH"), ':');
	i = 0;
	while (paths[i])
	{
		path = join_path(paths[i++], file);
		if (ft_filexists(path))
			break ;
		free(path);
		path = NULL;
	}
	ft_freearr_str(paths);
	return (path);
}
