/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:55:36 by yonadry           #+#    #+#             */
/*   Updated: 2023/04/22 09:19:00 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**args;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*free_lst;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		args = parsing(av, 0);
		add_to_list(&stack_a, args);
		free_arr((char **)args);
		sort_nums(&stack_a, &stack_b);
		while (stack_a)
		{
			free_lst = stack_a;
			stack_a = stack_a->next;
			free(free_lst);
		}
	}
	return (0);
}
