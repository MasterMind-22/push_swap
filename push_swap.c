/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:55:36 by yonadry           #+#    #+#             */
/*   Updated: 2023/03/31 00:49:01 by yonadry          ###   ########.fr       */
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
	t_list *lst = NULL;

	// atexit(fun);
	if (ac > 1)
	{
		args = parsing(av);
		add_to_list(&lst, args);
		if (ft_lstsize(lst) > 1 && (ft_lstsize(lst) <= 3))
			sort_3_nums(lst);
		// free_arr((void *)args);
		while (lst)
		{
			printf("%d\n", lst->content);
			free(lst);
			lst = lst->next;
		}
	}
	else
		ft_error();
	return (0);
}
