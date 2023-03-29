/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:57:52 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/28 17:57:52 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
		write(fd, &s[i], 1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = -1;
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	while (i < count * size)
		mem[i] = '\0';
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*str1;
	char	*str2;
	int		i;
	int		j;

	j = -1;
	i = -1;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!str1)
		str1 = ft_calloc(sizeof(char), 1);
	if (!str2)
		return (NULL);
	res = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!res)
		return (NULL);
	while (str1[++i])
		res[i] = str1[i];
	res[i] = '\0';
	while (str2[++j])
		res[i++] = str2[j];
	res[i] = '\0';
	free(str1);
	return (res);
}
