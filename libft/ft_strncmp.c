/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:50:56 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/10 19:51:06 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (ft_strlen(s1) != (n))
		return (1);
	while (n > 0 && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
		{
			return (int)(str1[i] - str2[i]);
		}
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (int)(str1[i] - str2[i]);
}