/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearsignals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:01:39 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:45:47 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void	ft_clearsignals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
