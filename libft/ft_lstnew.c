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

t_list			*ft_lstnew(char *str)
{
	t_list	*new;
	int		i;
	int		save;

	if (!str)
		return (0);
	save = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '=' && save == 0)
		{
			save = i;
			break ;
		}
	}
	if (save == 0)
		return (0);
	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new)
		return (0);
	new->key = ft_strdup(ft_substr(str, 0, save));
	if ((int)ft_strlen(str) == save)
		new->value = ft_strdup("");
	else
		new->value = ft_strdup(ft_substr(str, save + 1, ft_strlen(str)));
	new->next = 0;
	return (new);
}
