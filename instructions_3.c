/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:18:32 by yonadry           #+#    #+#             */
/*   Updated: 2023/04/22 08:18:35 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **stack_a, t_list **stack_b, int rrr)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (rrr)
		ft_putstr_fd("rrr\n", 1);
	return ;
}

void	pa(t_list **stack_a, t_list **stack_b, int pa)
{
	t_list	*head;

	head = *stack_b;
	if (!(*stack_b))
		return ;
	ft_lstadd_front(stack_a, ft_lst_new(head->content));
	(*stack_a)->index = (*stack_b)->index;
	*stack_b = (*stack_b)->next;
	free(head);
	if (pa)
		ft_putstr_fd("pa\n", 1);
	return ;
}

void	pb(t_list **stack_a, t_list **stack_b, int pb)
{
	t_list	*head;

	head = *stack_a;
	if (!(*stack_a))
		return ;
	head = *stack_a;
	ft_lstadd_front(stack_b, ft_lst_new(head->content));
	(*stack_b)->index = head->index;
	*stack_a = (*stack_a)->next;
	free(head);
	if (pb)
		ft_putstr_fd("pb\n", 1);
	return ;
}
