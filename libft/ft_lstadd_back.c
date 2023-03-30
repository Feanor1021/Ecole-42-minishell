/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:27:31 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:27:32 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	a = *lst;
	while (a->next != NULL)
		a = a->next;
	a->next = new;
}
