/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:28:20 by yonadry           #+#    #+#             */
/*   Updated: 2022/11/07 09:42:26 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;
	size_t	i;

	i = 0;
	a = (char *)dst;
	b = (char *)src;
	if (a == 0 && b == 0)
		return (NULL);
	if (a < b)
	{
		ft_memcpy(a, b, len);
	}
	if (a >= b)
	{
		while (len--)
		{
			a[len] = b[len];
		}
	}
	return (a);
}
