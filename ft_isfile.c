/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:31:44 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:54:43 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>

int	ft_isfile(char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return ((((path_stat.st_mode) & S_IFMT) == S_IFREG));
}
