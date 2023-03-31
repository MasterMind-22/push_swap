/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:59:16 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/30 21:13:34 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("\033[1;31mError\n\033[0m", 2);
	exit(1);
}

int	args_count(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void free_arr(void **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}