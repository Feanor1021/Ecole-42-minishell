/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:40:17 by akarabay          #+#    #+#             */
/*   Updated: 2022/09/09 14:43:56 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "minishell.h"
#include "42-Libft/libft.h"

static void	ft_putfd_str(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

int	ft_opendir(t_command *cmd)
{
	struct dirent	*de;
	DIR				*dr;

	dr = opendir(".");
	if (dr == NULL)
	{
		ft_putfd_str(2, "Could not open current directory" );
		return (0);
	}
	de = readdir(dr);
	while (de)
	{
		ft_addarr_str(&cmd->arguments, ft_strdup(de->d_name));
		de = readdir(dr);
	}
	closedir(dr);
	return (1);
}
