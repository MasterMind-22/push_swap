/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nums_3_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:37:37 by yonadry           #+#    #+#             */
/*   Updated: 2023/04/20 20:52:40 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_list(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->moves = i;
		i++;
		stack_a = stack_a->next;
	}
}

void	sort_3_numbers(t_list **stack_a)
{
	if ((((*stack_a)->content) < (*stack_a)->next->content
			&& ((*stack_a)->next->content) < (*stack_a)->next->next->content))
		return ;
	else if (ft_lstsize(*stack_a) == 2
		|| ((*stack_a)->content > (*stack_a)->next->content
			&& (*stack_a)->content < (*stack_a)->next->next->content))
		sa(*stack_a, 1);
	else if ((*stack_a)->content > (*stack_a)->next->content)
	{
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
		{
			ra(stack_a, 1);
			sa(*stack_a, 1);
		}
		else
			ra(stack_a, 1);
	}
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
	{
		rra(stack_a, 1);
		sa(*stack_a, 1);
	}
	else
		rra(stack_a, 1);
}

t_list	*get_list_min(t_list *stack_a)
{
	int		min;
	t_list	*lst_min;

	min = INT_MAX;
	while (stack_a)
	{
		if (stack_a->content < min)
		{
			min = stack_a->content;
			lst_min = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (lst_min);
}

void	sort_5_numbers(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst_min;

	while (ft_lstsize(*stack_a) != 3)
	{
		lst_min = get_list_min(*stack_a);
		index_list(*stack_a);
		while ((*stack_a) != lst_min)
		{
			if (lst_min->moves < 3)
				ra(stack_a, 1);
			else
				rra(stack_a, 1);
		}
		pb(stack_a, stack_b);
	}
	sort_3_numbers(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_nums(t_list **stack_a, t_list **stack_b)
{
	index_list_min_to_max(stack_a);
	if (ft_lstsize(*stack_a) == 1)
		return ;
	if (ft_lstsize(*stack_a) <= 3)
		sort_3_numbers(stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		sort_5_numbers(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) < 10)
		push_to_b(stack_a, stack_b, 2);
	else if (ft_lstsize(*stack_a) <= 100)
		push_to_b(stack_a, stack_b, 5);
	else if (ft_lstsize(*stack_a) <= 500)
		push_to_b(stack_a, stack_b, 9);
	if (*stack_b)
		push_to_a(stack_a, stack_b);
}
