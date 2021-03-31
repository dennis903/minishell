/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 03:57:13 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/08 02:01:59 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*de;
	unsigned char	*sr;

	if (!dest && !src)
		return (0);
	de = (unsigned char *)dest;
	sr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		de[i] = sr[i];
		i++;
	}
	return (de);
}
