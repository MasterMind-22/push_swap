/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:38:34 by yonadry           #+#    #+#             */
/*   Updated: 2022/11/07 09:44:37 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_str(char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			counter++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (counter);
}

static	void	free_strs(char **strs, int i)
{
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		start;
	int		j;
	char	**strs;

	i = -1;
	if (!s)
		return (NULL);
	strs = (char **)malloc((count_str(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	j = 0;
	while (++i < count_str(s, c))
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		start = j;
		while (s[j] != '\0' && s[j] != c)
			j++;
		strs[i] = ft_substr(s, start, j - start);
		if (!strs[i])
			return (free_strs(strs, 0), NULL);
	}
	strs[i] = NULL;
	return (strs);
}
