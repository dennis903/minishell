/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 04:39:19 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/08 02:30:22 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*de;
	unsigned char	*sr;

	de = (unsigned char *)dst;
	sr = (unsigned char *)src;
	i = 0;
	while (i < (int)n)
	{
		de[i] = sr[i];
		if (sr[i] == (unsigned char)c)
		{
			i++;
			return (&de[i]);
		}
		i++;
	}
	return (0);
}
