/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlyexport.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:10:09 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:52:20 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "42-Libft/libft.h"

static void	sort(char **arr)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (arr[i][0] > arr[j][0])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static char	*double_quotes(char *s)
{
	char	*buffer;
	int		len;

	len = ft_strlen(s);
	if (!len)
		return (ft_strdup("\"\""));
	buffer = ft_calloc(len + 3, sizeof(char));
	buffer[0] = '\"';
	ft_memmove(s, buffer + 1, len);
	buffer[len + 1] = '\"';
	free(s);
	return (buffer);
}

static void	__onlyexport(char ***env, t_command *command, int i)
{
	sort(*env);
	i = -1;
	while ((*env)[++i])
	{
		ft_putstr_fd("declare -x", command->out);
		ft_putendl_fd((*env)[i], command->out);
	}
	ft_freearr_str(*env);
}

void	ft_onlyexport(t_command *command)
{
	int		i;
	char	*key;
	char	*value;
	char	**env;

	env = ft_calloc(sizeof(char *), ft_arrlen((void **)g_mini->env) + 1);
	i = -1;
	while (g_mini->env[++i])
	{
		if (ft_strchr(g_mini->env[i], '='))
		{
			key = ft_get_key(g_mini->env[i]);
			value = ft_get_value(g_mini->env[i]);
			value = double_quotes(value);
			ft_strappend(&key, "=");
			ft_strappend(&key, value);
			free(value);
			env[i] = key;
		}
		else
			env[i] = ft_strdup(g_mini->env[i]);
	}
	__onlyexport(&env, command, -1);
}
