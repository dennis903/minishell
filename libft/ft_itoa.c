/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukheon <ukheon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:38:40 by ukheon            #+#    #+#             */
/*   Updated: 2020/10/13 17:12:34 by ukheon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*putstr(char *res, int n, int len)
{
	long long int	swap;

	swap = n;
	if (swap == 0)
	{
		res[0] = 0 + '0';
		return (res);
	}
	else if (swap < 0)
	{
		res[0] = '-';
		len += 1;
		swap *= -1;
	}
	while (swap)
	{
		res[len] = (swap % 10) + '0';
		swap = swap / 10;
		len--;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		save_n;
	int		len;
	int		check;

	check = 0;
	len = 0;
	save_n = n;
	if (n == 0)
		len = 1;
	if (save_n < 0)
	{
		check = 1;
		save_n *= -1;
	}
	while (save_n)
	{
		save_n = save_n / 10;
		len++;
	}
	if (!(res = (char *)malloc(sizeof(char) * (len + check + 1))))
		return (0);
	res = putstr(res, n, len - 1);
	res[len + check] = '\0';
	return (res);
}
