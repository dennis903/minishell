/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:35:43 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/07 23:17:50 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	int				i;
	unsigned char	*res;

	res = (unsigned char *)ptr;
	i = 0;
	while (i < (int)num)
	{
		res[i] = value;
		i++;
	}
	return (res);
}
