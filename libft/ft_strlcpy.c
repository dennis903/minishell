/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukheon <ukheon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 04:02:53 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/12 19:34:50 by ukheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			len;

	len = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (size == 0)
	{
		while (src[len])
			len++;
		return (len);
	}
	i = 0;
	while (size - 1 > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i] = '\0';
	while (src[len])
		len++;
	return (len);
}
