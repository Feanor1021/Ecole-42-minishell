/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:12:23 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:12:30 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_len(char *s)
{
	int	i;

	i = 0;
	while (is_env(s[i]) && s[i])
		i++;
	return (i);
}

static char	*ft_take_env(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '$' && token[i + 1] && token[i + 1] == '?')
			return (ft_strdup("$?"));
		else if (token[i] == '$' && token[i + 1] && !is_alpha_underscore(token[i
					+ 1]))
			return (ft_substr(token, i, 2));
		else if (token[i] == '$' && token[i + 1] && is_env(token[i + 1]))
			return (ft_substr(token, i, (env_len(token + i + 1) + 1)));
		i++;
	}
	return (0);
}

char	*change_env_with_value(char *token)
{
	char	*env;
	char	*env_value;

	while (1)
	{
		env = ft_take_env(token);
		if (!env)
			break ;
		if (ft_strnstr(env, "$?", ft_strlen(env)) && ft_strlen(env) == 2)
		{
			env_value = ft_itoa(g_shell->return_code);
			replace_with(&token, env, env_value);
			free(env_value);
		}
		else
		{
			env_value = get_env(env + 1);
			replace_with(&token, env, env_value);
		}
		free(env);
	}
	return (token);
}
