/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:24:36 by ukheon            #+#    #+#             */
/*   Updated: 2020/10/13 19:20:53 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n > 10)
	{
		ft_putnbr(n / 10, fd);
		write(fd, &"0123456789"[n % 10], 1);
	}
	else if (n >= 0)
		write(fd, &"0123456789"[n % 10], 1);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_putnbr(n, fd);
	}
}

void				ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
