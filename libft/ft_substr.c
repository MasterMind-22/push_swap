/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:46:50 by yonadry           #+#    #+#             */
/*   Updated: 2022/11/10 02:53:21 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	char	*str;
	size_t	l;

	str = (char *)s;
	if (!s)
		return (NULL);
	l = ft_strlen(str);
	i = 0;
	if (len == 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > l)
		len = l;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && start < ft_strlen(str))
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
