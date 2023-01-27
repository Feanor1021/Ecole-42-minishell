/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:05:04 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:48:30 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"
#include "minishell.h"

static int	ft_howmany_envchars(char *s)
{
	int	i;

	i = 0;
	while (ft_is_env(s[i]) && s[i])
		i++;
	return (i);
}

static char	*ft_take_env(char *s)
{
	int	i;
	int	env_strlen;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && s[i + 1] && s[i + 1] == '?')
			return (ft_strdup("$?"));
		else if (s[i] == '$' && s[i + 1] && !ft_isalpha_underscore(s[i + 1]))
			return (ft_substr(s, i, 2));
		else if (s[i] == '$' && s[i + 1] && ft_is_env(s[i + 1]))
		{
			env_strlen = ft_howmany_envchars(s + i + 1);
			return (ft_substr(s, i, env_strlen + 1));
		}
		i++;
	}
	return (0);
}

char	*change_env_with_value(char *s)
{
	char	*first_env;
	char	*env_value;

	while (1)
	{
		first_env = ft_take_env(s);
		if (!first_env)
			break ;
		if (ft_strnstr(first_env, "$?", ft_strlen(first_env)) \
		&& (ft_strlen(first_env) == 2))
		{
			env_value = ft_itoa(g_mini->return_code);
			ft_replace(&s, first_env, env_value);
			free(env_value);
		}
		else
		{
			env_value = ft_getenv(first_env + 1);
			ft_replace(&s, first_env, env_value);
		}
		free(first_env);
	}
	return (s);
}
