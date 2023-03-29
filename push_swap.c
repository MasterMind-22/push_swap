/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:55:36 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/28 18:02:56 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void fun()
// {
//     system("leaks push_swap");
// }

int	main(int ac, char **av)
{
	// atexit(fun);
	if (ac > 1)
	{
		parsing(av);
		// while(1)
	}
	else
		ft_error();
	return (0);
}
