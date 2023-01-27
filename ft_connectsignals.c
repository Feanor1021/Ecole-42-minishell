/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connectsignals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:59:23 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:45:58 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void	ft_connectsignals(void)
{
	signal(SIGINT, ft_signalhandler);
	signal(SIGQUIT, SIG_IGN);
}
