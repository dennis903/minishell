/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:43:04 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/25 16:37:35 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_whitespace(char str)
{
	if ((str >= 9 && str <= 13) || str == ' ' || str == '\0')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long long int		num;
	int					i;
	int					sign;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] && ft_whitespace(str[i]) == 1)
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
		if ((num * sign) <= -2147483649)
			return (0);
		else if ((num * sign) >= 2147483648)
			return (-1);
	}
	return (num * sign);
}
