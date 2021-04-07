/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:57:34 by ukheon            #+#    #+#             */
/*   Updated: 2020/10/21 18:50:47 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	int			s1_len;
	int			s2_len;

	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * s1_len + s2_len + 1)))
		return (0);
	ft_strlcpy(res, s1, s1_len + 1);
	ft_strlcat(res + s1_len, s2, s2_len + 1);
	return (res);
}

char			*ft_strdup(const char *s1)
{
	int		i;
	char	*res;
	char	*str;

	str = (char *)s1;
	i = 0;
	while (str[i])
		i++;
	if (!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

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

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	return (i + ft_strlen(src));
}

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
