/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:12:20 by ukheon            #+#    #+#             */
/*   Updated: 2020/10/13 19:02:17 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstsize(t_list *lst)
{
	t_list	*new;
	int		len;

	if (!lst)
		return (0);
	len = 0;
	new = lst;
	while (new)
	{
		new = new->next;
		len++;
	}
	return (len);
}

