/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:35:43 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/08 05:41:20 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;
	char		*last;

	last = (char *)s;
	len = 0;
	while (s[len])
		len++;
	while (len > 0)
	{
		if (last[len] == (char)c)
		{
			return (&last[len]);
		}
		len--;
	}
	if (last[len] == (char)c)
		return (last + len);
	return (0);
}
