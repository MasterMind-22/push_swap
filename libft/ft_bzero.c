/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:45:02 by yonadry           #+#    #+#             */
/*   Updated: 2022/10/13 16:36:23 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)s;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}
