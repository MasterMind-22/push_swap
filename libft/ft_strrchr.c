/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:11:34 by yonadry           #+#    #+#             */
/*   Updated: 2022/10/18 18:38:47 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	srcl;

	srcl = ft_strlen(str);
	while (srcl >= 0)
	{
		if (str[srcl] == (char) c)
			return ((char *)str + srcl);
		srcl--;
	}
	return (NULL);
}
