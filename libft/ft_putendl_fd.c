/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:16:47 by ukheon            #+#    #+#             */
/*   Updated: 2020/10/14 14:35:24 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putendl_fd(char const *s, int fd)
{
	int			i;
	char		*str;

	if (!s)
		return ;
	str = (char *)s;
	i = 0;
	if (fd < 0)
		return ;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
