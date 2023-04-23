/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:59:16 by yonadry           #+#    #+#             */
/*   Updated: 2023/04/23 15:27:16 by yonadry          ###   ########.fr       */
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

void	free_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	index_list_min_to_max(t_list **stack_a)
{
	t_list	*head;
	t_list	*tmp;
	int		i;

	head = *stack_a;
	tmp = *stack_a;
	i = ft_lstsize(head);
	while (i--)
	{
		head = (*stack_a);
		while (head)
		{
			if (tmp->content > head->content)
				tmp->index++;
			head = head->next;
		}
		tmp = tmp->next;
	}
}

void	add_to_list(t_list **lst, char **av)
{
	int	i;

	i = -1;
	while (av[++i])
		ft_lstadd_back(lst, ft_lst_new(ft_atoi(av[i])));
}
