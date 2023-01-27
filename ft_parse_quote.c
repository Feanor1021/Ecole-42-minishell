/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:10:57 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/03 20:44:29 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static void	ft_check_double_quotes(char *s, char **all_tokens, int *index)
{
	int		end;
	char	*tmp_token;
	char	*tmp_env_value;

	if (s[*index + 1] && s[*index + 1] == '"')
		*index += 2;
	else
	{
		ft_get_end_numbers_dbquotes(s + ++(*index), &end);
		tmp_token = ft_substr(s, *index, end);
		tmp_env_value = change_env_with_value(tmp_token);
		ft_strappend(all_tokens, tmp_env_value);
		free(tmp_env_value);
		*index += end + 1;
	}
}

static void	ft_check_single_quote(char *s, char **all_tokens, int *index)
{
	int		end;
	char	*tmp_token;

	if (s[*index + 1] && s[*index + 1] == '\'')
		*index += 2;
	else
	{
		ft_get_end_numbers_quote(s + ++(*index), &end);
		tmp_token = ft_substr(s, *index, end);
		ft_strappend(all_tokens, tmp_token);
		free(tmp_token);
		*index += end + 1;
	}
}

static void	ft_check_without_quote(char *s, char **all_tokens, int *index)
{
	int		end;
	char	*tmp_token;
	char	*tmp_env_value;

	ft_get_len_of_word(s + (*index), &end);
	tmp_token = ft_substr(s, *index, end);
	tmp_env_value = change_env_with_value(tmp_token);
	ft_strappend(all_tokens, tmp_env_value);
	free(tmp_env_value);
	*index += end;
}

char	*ft_pars_quote_first(char *token)
{
	int		index;
	char	*all_tokens;

	all_tokens = ft_calloc(sizeof(char), 1);
	index = 0;
	while (token[index])
	{
		if (token[index] == '"')
			ft_check_double_quotes(token, &all_tokens, &index);
		else if (token[index] == '\'')
			ft_check_single_quote(token, &all_tokens, &index);
		else
			ft_check_without_quote(token, &all_tokens, &index);
	}
	free(token);
	return (all_tokens);
}

void	ft_pars_quote(t_command *cmd)
{
	int	i;

	if (cmd->command)
		cmd->command = ft_pars_quote_first(cmd->command);
	i = 0;
	while (cmd->arguments && cmd->arguments[i])
	{
		cmd->arguments[i] = ft_pars_quote_first(cmd->arguments[i]);
		i++;
	}
	ft_clean_array(cmd);
}
