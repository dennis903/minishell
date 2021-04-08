/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:46:31 by ukwon             #+#    #+#             */
/*   Updated: 2021/04/08 21:26:31 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		getstart(char const *s1, char const *set)
{
	size_t		i;
	size_t		len;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int		getend(char const *s1, char const *set)
{
	size_t		len;
	size_t		i;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[len - 1 - i]) == 0)
			break ;
		i++;
	}
	return (len - i - 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	if (!s1)
		return (0);
	if (!set)
		return (0);
	start = getstart(s1, set);
	end = getend(s1, set);
	if (start > end)
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * end - start + 2)))
		return (0);
	ft_strlcpy(res, s1 + start, end - start + 2);
	return (res);
}
