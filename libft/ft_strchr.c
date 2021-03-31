/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 05:09:27 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/10 19:00:02 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	int			len;
	char		*str;

	str = (char *)s;
	len = 0;
	while (str[len])
	{
		if (str[len] == (char)c)
		{
			return (&str[len]);
		}
		len++;
	}
	if (str[len] == (char)c)
		return (str + len);
	return (0);
}
