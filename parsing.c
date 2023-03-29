/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:01:34 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/28 18:03:27 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < 9 || (str[i] > 9 && str[i] < 32) || (str[i] > 32
				&& str[i] < 48) || str[i] > 57)
			ft_error();
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		i++;
	}
	if (res * sign < INT_MIN || res * sign > INT_MAX)
		ft_error();
	return (res * sign);
}

void	check_dups(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < args_count(av))
	{
		j = i + 1;
		while (j < args_count(av))
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				ft_error();
			j++;
		}
		i++;
	}
}

void	check_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == 9 || str[i] == '-' || str[i] == '+')
		i++;
	if (i == ft_strlen(str))
		ft_error();
}

void	is_sorted(char **str)
{
	int	i;
	int	max;

	i = 0;
	max = 1;
	if (args_count(str) == 1)
		return ;
	while (i < args_count(str) - 1)
	{
		if (ft_atoi(str[i]) < ft_atoi(str[i + 1]))
			max++;
		i++;
	}
	if (max == args_count(str))
	{
		ft_error();
		return ;
	}
}

void	parsing(char **av)
{
	int		i;
	char	*save;
	char	**save1;

	i = 1;
	save = NULL;
    while (av[i])
	{
		check_empty(av[i]);
		save = ft_strjoin(save, av[i]);
		save = ft_strjoin(save, " ");
		i++;
	}
	save1 = ft_split(save, ' ');
	is_sorted(save1);
	check_dups(save1);
	i = 0;
	while (save1[i])
	{
		free(save1[i]);
		i++;
	}
	free(save1);
	free(save);
}
