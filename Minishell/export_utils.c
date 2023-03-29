/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:14:59 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:15:08 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*add_double_quote(char *s)
{
	char	*buff;
	char	*buff2;

	if (!s)
		s = ft_strdup("");
	buff = ft_strjoin("\"", s);
	free(s);
	buff2 = ft_strjoin(buff, "\"");
	free(buff);
	return (buff2);
}

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

static void	print_wo_arg_export(char **env, t_command *cmd, int i)
{
	sort(env);
	while (env[++i])
	{
		ft_putstr_fd("declare -x ", cmd->out);
		ft_putendl_fd(env[i], cmd->out);
	}
	ft_free_arr_str(env);
}

void	export_wo_argument(t_command *cmd)
{
	int		i;
	char	*key;
	char	*value;
	char	**env;

	env = ft_calloc(sizeof(char *), ft_arrlen((void **)g_shell->env) + 1);
	i = -1;
	while (g_shell->env[++i])
	{
		if (ft_strchr(g_shell->env[i], '='))
		{
			key = get_key(g_shell->env[i]);
			value = get_value(g_shell->env[i]);
			value = add_double_quote(value);
			append_str(&key, "=");
			append_str(&key, value);
			free(value);
			env[i] = key;
		}
		else
			env[i] = ft_strdup(g_shell->env[i]);
	}
	print_wo_arg_export(env, cmd, -1);
}
