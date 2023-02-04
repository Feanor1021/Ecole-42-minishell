/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:58:47 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/15 11:58:50 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*return_list;
	t_list	*no;

	return_list = 0;
	while (lst)
	{
		no = ft_lstnew(f(lst->content));
		if (!no)
		{
			ft_lstclear(&return_list, del);
			return (NULL);
		}
		ft_lstadd_back(&return_list, no);
		lst = lst->next;
	}
	return (return_list);
}
