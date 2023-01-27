/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wilcard_parse_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarabay <akarabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:10:35 by akarabay          #+#    #+#             */
/*   Updated: 2022/09/09 14:40:03 by akarabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_star_state(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] == '*')
	{
		if (str[0] == '*')
			return (DB_STARS);
		else
			return (RIGHT_STAR);
	}
	else if (str[0] == '*')
		return (LEFT_STAR);
	return (0);
}

char	*ft_only_word(char *str)
{
	char	*tmp;

	while (*str && *str == '*')
		str++;
	tmp = ft_substr(str, 0, ft_strlenchr(str, '*'));
	return (tmp);
}

int	ft_total_words(char *str, int index, int count)
{
	while (str[index])
	{
		while (str[index] && str[index] == '*')
			index++;
		if (str[index] && str[index] != '*')
			count++;
		while (str[index] && str[index] != '*')
			index++;
	}
	return (count);
}

char	*ft_strstr_last(char *haystack, char *needle)
{
	int	i;
	int	j;

	if (!*needle)
		return (haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	i = ft_strlen(haystack) - ft_strlen(needle);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j])
			j++;
		if (!needle[j])
			return (haystack + i);
		i++;
	}
	return (NULL);
}

int	ft_check_star(t_command *command)
{
	int	i;

	i = 0;
	if (command->subshells)
		return (0);
	if (command->arguments && ft_strchr(command->arguments[0], '*'))
		ft_first_star(command);
	while (command->arguments && command->arguments[++i])
		if (ft_strchr(command->arguments[i], '*'))
			return (1);
	return (0);
}
