/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:46:05 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/20 15:11:33 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include "42-Libft/libft.h"

static void	remove_nullstring(t_command *cmd, int total_zero)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;

	len = ft_arrlen((void **)cmd->arguments);
	tmp = ft_calloc(sizeof(char *), len - total_zero + 1);
	i = -1;
	j = 0;
	while (cmd->arguments && cmd->arguments[++i])
	{
		if (ft_strlen(cmd->arguments[i]) == 0)
		{
			j++;
			free(cmd->arguments[i]);
		}
		else
			tmp[i - j] = cmd->arguments[i];
	}
	free(cmd->arguments);
	cmd->arguments = tmp;
}

void	ft_clean_array(t_command *cmd)
{
	int		i;
	int		total_zero;

	i = -1;
	total_zero = 0;
	while (cmd->arguments && cmd->arguments[++i])
	{
		if (ft_strlen(cmd->arguments[i]) == 0)
			total_zero++;
	}
	remove_nullstring(cmd, total_zero);
}
