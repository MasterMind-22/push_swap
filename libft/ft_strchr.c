/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:29:24 by yonadry           #+#    #+#             */
/*   Updated: 2022/11/01 09:35:48 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int find)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str);
	while (i <= j)
	{
		if (str[i] == (char) find)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
