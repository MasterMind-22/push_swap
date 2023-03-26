/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:59:30 by yonadry           #+#    #+#             */
/*   Updated: 2022/11/05 11:08:30 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issame(char find, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == find)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	if (s1 == 0)
		return (NULL);
	if (set == 0)
		return ((char *)s1);
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_issame((char)s1[i], (char *)set))
		i++;
	while (j >= 0 && ft_issame((char)s1[j], (char *)set))
		j--;
	if (j == -1)
		return (ft_substr(s1, i, 0));
	return (ft_substr(s1, i, j - i + 1));
}
