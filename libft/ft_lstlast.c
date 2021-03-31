/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:27:47 by ukheon            #+#    #+#             */
/*   Updated: 2020/10/13 19:02:43 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstlast(t_list *lst)
{
	t_list *new;

	if (!lst)
		return (0);
	new = lst;
	while (new->next)
		new = new->next;
	return (new);
}
