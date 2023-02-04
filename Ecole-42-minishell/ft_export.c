/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:29:01 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:46:36 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"
#include "42-Libft/libft.h"

static void	set_reset(char *s)
{
	char	*key;
	char	*value;

	if (!ft_strchr(s, '='))
	{
		ft_setenv(s, 0);
		return ;
	}
	value = ft_get_value(s);
	key = ft_get_key(s);
	if (!value)
	{
		ft_setenv(key, "");
		return ;
	}
	ft_setenv(key, value);
}

int	ft_export(t_command *command)
{
	int		i;

	i = 0;
	if (!command->arguments[1])
		ft_onlyexport(command);
	else
	{
		while (command->arguments[++i])
		{
			if (ft_env_check(command->arguments[i]))
				set_reset(command->arguments[i]);
			else
			{
				ft_putstr_fd("bash: export: '", 2);
				ft_putstr_fd(command->arguments[i], 2);
				ft_putendl_fd("':not a valid identifier", 2);
				return (1);
			}
		}
	}
	return (0);
}
