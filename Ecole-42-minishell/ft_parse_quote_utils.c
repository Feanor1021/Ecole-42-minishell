/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quote_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:31:38 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/03 13:05:57 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_get_end_numbers_dbquotes(char *s, int *end)
{
	int	index;

	index = -1;
	*end = -1;
	while (++index || 1)
	{
		(*end)++;
		if (s[index] == '"' || !s[index])
			return ;
	}
}

void	ft_get_end_numbers_quote(char *s, int *end)
{
	int	index;

	index = -1;
	*end = -1;
	while (++index || 1)
	{
		(*end)++;
		if (s[index] == '\'' || !s[index])
			return ;
	}
}

void	ft_get_len_of_word(char *s, int *end)
{
	int	index;

	index = -1;
	*end = 0;
	while (s[++index] && !(s[index] == '"' || s[index] == '\''))
		(*end)++;
}
