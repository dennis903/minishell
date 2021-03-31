/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:40:40 by ukheon            #+#    #+#             */
/*   Updated: 2020/10/13 19:18:21 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char				*res;
	unsigned int		i;

	i = 0;
	if (s == 0 || f == 0)
		return (0);
	if (!(res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
