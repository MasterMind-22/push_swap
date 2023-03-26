/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:57:59 by yonadry           #+#    #+#             */
/*   Updated: 2022/11/10 02:56:45 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*a;
	char	*b;

	i = 0;
	b = (char *)src;
	a = (char *)dst;
	if (a == 0 && b == 0 && n != 0)
		return (0);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}
