/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:15:27 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:15:34 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value(char *s)
{
	int		len_to_eq;
	int		len_of_value;
	char	*value;

	len_to_eq = ft_strchr(s, '=') - s;
	len_of_value = ft_strlen(s + len_to_eq + 1);
	if (!len_of_value)
		return (0);
	value = ft_substr(s, len_to_eq + 1, len_of_value);
	return (value);
}

char	*get_key(char *s)
{
	int		len;
	char	*key;

	len = ft_strchr(s, '=') - s;
	key = ft_substr(s, 0, len);
	return (key);
}

static void	set_reset(char *s)
{
	char	*key;
	char	*value;

	if (!ft_strchr(s, '='))
	{
		set_env(s, 0);
		return ;
	}
	value = get_value(s);
	key = get_key(s);
	if (!value)
	{
		set_env(key, ft_strdup(""));
		return ;
	}
	set_env(key, value);
}

int	env_check(char *s)
{
	int	i;

	i = 0;
	if (!is_alpha_underscore(s[i++]))
		return (0);
	while (s[i] && s[i] != '=')
	{
		if (!is_env(s[i++]))
			return (0);
	}
	return (1);
}

int	ft_export(t_command *command)
{
	int	i;

	i = 0;
	if (!command->arguments[1])
		export_wo_argument(command);
	else
	{
		while (command->arguments[++i])
		{
			if (env_check(command->arguments[i]))
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
