/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:55:36 by yonadry           #+#    #+#             */
/*   Updated: 2023/04/03 21:01:05 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fun()
{
    system("leaks push_swap");
}

void add_to_list(t_list **lst , char **av)
{
	int i;

	i = -1;
	while (av[++i])
		ft_lstadd_back(lst, ft_lst_new(ft_atoi(av[i])));
}


int	main(int ac, char **av)
{
	char **args;
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;

	// atexit(fun);
	if (ac > 1)
	{
		args = parsing(av);
		add_to_list(&stack_a, args);
		sort_3_nums(&stack_a, &stack_b);
		while ((stack_a))
		{
			printf("%d === %d\n", (stack_a)->content , (stack_a)->index);
			(stack_a) = (stack_a)->next;
		}
			printf("\n=========================\nb: \n");
		while (stack_b)
		{
			printf("%d ", stack_b->content);
			stack_b = stack_b->next;
		}
	}
	else
		ft_error();
	return (0);
}