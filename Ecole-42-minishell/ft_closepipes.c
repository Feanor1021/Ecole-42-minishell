/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closepipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:44:59 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:45:51 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void	ft_closepipes(void)
{
	int	i;

	i = 0;
	while (i < g_mini->pipecount)
		close(g_mini->openedpipes[i++]);
	free(g_mini->openedpipes);
	g_mini->pipecount = 0;
	g_mini->openedpipes = NULL;
}
