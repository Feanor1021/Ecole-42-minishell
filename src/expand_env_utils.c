/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:12:03 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:47:12 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	new_str_len(char *str, char *a, char *b, char *target)
{
	int	len;
	int	i;
	int	k;

	len = 0;
	while (str + len != target)
		len++;
	i = 0;
	k = len;
	while (str[k] == a[i])
	{
		k++;
		i++;
	}
	len += ft_strlen(str + k);
	len += ft_strlen(b);
	return (len);
}

static char	*replace_str(char *str, char *a, char *b, char *target)
{
	char	*ret;
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	ret = ft_calloc(sizeof(char), new_str_len(str, a, b, target) + 2);
	while (str + len != target)
		ret[j++] = str[len++];
	while (str[len] && a[i] && str[len] == a[i])
	{
		len++;
		i++;
	}
	k = 0;
	while (b[k])
		ret[j++] = b[k++];
	while (str[len])
		ret[j++] = str[len++];
	free(str);
	return (ret);
}

void	replace_with(char **str, char *a, char *b)
{
	char	*target;

	target = ft_strnstr(*str, a, ft_strlen(*str));
	if (b && target)
	{
		*str = replace_str(*str, a, b, target);
		target = ft_strnstr(*str, a, ft_strlen(*str));
	}
	else if (!b)
	{
		ft_strnstr(*str, a, ft_strlen(*str));
		ft_memmove(ft_strnstr(*str, a, ft_strlen(*str)),
			ft_strnstr(*str, a, ft_strlen(*str)) + ft_strlen(a),
			ft_strlen(*str));
	}
}

int	get_env_index(char *name)
{
	int		i;
	int		k;
	int		index;
	char	**env;

	if (name[0] == '$')
		name++;
	index = 0;
	env = g_shell->env;
	while (env[index])
	{
		i = 0;
		k = 0;
		while (env[index][i] && env[index][i] == name[k])
		{
			i++;
			k++;
		}
		if ((!name[k] && env[index][i] == '=') || !env[index][i])
			return (index);
		index++;
	}
	return (-1);
}

char	*get_env(char *arr)
{
	int		i;
	int		env_index;
	char	*env;

	env_index = get_env_index(arr);
	if (env_index == -1)
		return (NULL);
	env = g_shell->env[env_index];
	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	if (env[i] == '=')
		i++;
	return (env + i);
}
