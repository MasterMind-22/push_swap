/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:15:38 by yonadry           #+#    #+#             */
/*   Updated: 2022/11/05 10:01:40 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static	char	*reverser(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
	return (s);
}

static int	nbrcounter(int n)
{
	int	counter;

	counter = 0;
	if (n < 0 || n == 0)
	{
		counter += 1;
	}
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*ntostr;
	int		nbrlen;
	long	cast;
	int		i;

	i = 0;
	cast = (long)n;
	nbrlen = nbrcounter(cast);
	ntostr = malloc(nbrlen + 1);
	if (!ntostr)
		return (NULL);
	if (cast < 0)
	{
		ntostr[nbrlen - 1] = '-';
		cast *= (-1);
	}
	if (cast == 0)
		ntostr[nbrlen - 1] = '0';
	while (cast != 0)
	{
		ntostr[i++] = (cast % 10) + 48;
		cast /= 10;
	}
	ntostr[nbrlen] = '\0';
	return (reverser(ntostr));
}
