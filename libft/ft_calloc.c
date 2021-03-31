/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukwon <ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:44:45 by ukwon             #+#    #+#             */
/*   Updated: 2020/10/11 20:03:13 by ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t num1, size_t num2)
{
	void	*res;

	if (num1 == 0 && num2 == 0)
	{
		if (!(res = (void *)malloc(sizeof(void) * 1)))
			return (0);
		ft_bzero(res, (num1 * num2));
		return (res);
	}
	if (!(res = (void *)malloc(num2 * num1)))
		return (0);
	ft_bzero(res, (num1 * num2));
	return (res);
}
