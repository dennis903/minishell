/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukheon <ukheon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 21:15:09 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/14 02:05:06 by ukheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;

	if (!lst)
		return (0);
	if (!(head = ft_lstnew((*f)(lst->content))))
		return (0);
	lst = lst->next;
	new = lst;
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
