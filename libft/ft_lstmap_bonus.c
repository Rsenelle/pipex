/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 04:05:09 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/16 17:31:36 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*second;

	if (!lst && !f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		second = ft_lstnew(f(lst->content));
		if (!second)
		{
			ft_lstclear(&second, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&first, second);
	}
	return (first);
}
