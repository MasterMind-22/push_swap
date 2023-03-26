/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:03:29 by yonadry           #+#    #+#             */
/*   Updated: 2022/11/08 13:10:17 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	srclen = ft_strlen(src);
	if ((!dst && !len) || !len)
		return (srclen);
	dstlen = ft_strlen(dst);
	j = dstlen;
	i = 0;
	if (len < dstlen)
		return (srclen + len);
	while (src[i] != '\0' && (i + dstlen < len - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (srclen + dstlen);
}
