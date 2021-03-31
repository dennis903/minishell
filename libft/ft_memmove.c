/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:49:07 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/08 01:30:35 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sr;
	size_t			i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		dest = (unsigned char *)dst;
		sr = (unsigned char *)src;
		while (len--)
		{
			dest[i] = sr[i];
			i++;
		}
	}
	else
	{
		dest = dst + (len - 1);
		sr = (unsigned char *)src + (len - 1);
		while (len--)
			*dest-- = *sr--;
	}
	return (dst);
}
