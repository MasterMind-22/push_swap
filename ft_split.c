#include "push_swap.h"

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
		return (ft_calloc(sizeof(char), 1));
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