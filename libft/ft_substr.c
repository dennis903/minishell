/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:51:03 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/13 21:45:00 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	int				i;
	char			*str;
	int				s_len;

	if (!s && len < 0)
		return (NULL);
	s_len = 0;
	str = (char *)s;
	while (str[s_len])
		s_len++;
	if ((int)start > (int)ft_strlen(str))
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (len--)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
