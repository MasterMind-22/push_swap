/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:18:10 by yonadry           #+#    #+#             */
/*   Updated: 2023/04/22 08:18:20 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a, int a)
{
	int	tmp;
	int	index;

	if (!stack_a)
		return ;
	tmp = stack_a->next->content;
	index = stack_a->next->index;
	stack_a->next->content = stack_a->content;
	stack_a->next->index = stack_a->index;
	stack_a->content = tmp;
	stack_a->index = index;
	if (a)
		ft_putstr_fd("sa\n", 1);
	return ;
}

void	sb(t_list *stack_b, int b)
{
	int	tmp;
	int	index;

	if (!stack_b)
		return ;
	tmp = stack_b->next->content;
	index = stack_b->next->index;
	stack_b->next->content = stack_b->content;
	stack_b->next->index = stack_b->index;
	stack_b->content = tmp;
	stack_b->index = index;
	if (b)
		ft_putstr_fd("sb\n", 1);
	return ;
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_putstr_fd("ss\n", 1);
	return ;
}

void	ra(t_list **stack_a, int a)
{
	t_list	*head;

	if (!(*stack_a))
		return ;
	head = *stack_a;
	ft_lstadd_back(stack_a, ft_lst_new(head->content));
	ft_lstlast(*stack_a)->index = (*stack_a)->index;
	(*stack_a) = (*stack_a)->next;
	free(head);
	if (a)
		ft_putstr_fd("ra\n", 1);
	return ;
}

void	rb(t_list **stack_b, int a)
{
	t_list	*head;

	if (!(*stack_b))
		return ;
	head = *stack_b;
	ft_lstadd_back(stack_b, ft_lst_new(head->content));
	ft_lstlast(head)->index = (head)->index;
	(*stack_b) = (*stack_b)->next;
	free(head);
	if (a)
		ft_putstr_fd("rb\n", 1);
}
