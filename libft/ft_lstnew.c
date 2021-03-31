/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:05:32 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/13 19:02:29 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void *str)
{
	t_list	*new;
	char	**split;
	int		i;

	if (!str)
		return (0);
	i = 0;
	split = ft_split(str, '=');
	while (split[i])
		i++;
	if (i != 1 && i != 2)
		return (0);
	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new)
		return (0);
	new->key = split[0];
	new->value = split[1];
	new->next = 0;
	return (new);
}
