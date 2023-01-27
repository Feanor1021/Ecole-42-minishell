/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:26:40 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:49:18 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "minishell.h"
#include "42-Libft/libft.h"

char	*ft_readfile(char *path)
{
	char	*ret;
	char	buff[1024];
	int		fd;
	int		readed;

	ret = NULL;
	fd = open(path, O_RDONLY);
	while (1)
	{
		readed = read(fd, buff, sizeof(buff));
		if (readed == 0 || readed == -1)
			break ;
		buff[readed] = 0;
		ft_strappend(&ret, buff);
	}
	close(fd);
	return (ret);
}
