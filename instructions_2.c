#include "push_swap.h"

void rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
	return;
}

void rra(t_list **stack_a, int a)
{
	t_list *last = *stack_a;
	t_list *b_last = NULL;

	if (!(*stack_a))
		return;
	while (last->next)
	{
		b_last = last;
		last = last->next;
	}
	last->next = *stack_a;
	b_last->next = NULL;
	*stack_a = last;
	if (a)
		ft_putstr_fd("rra\n", 1);
	return;
}

void rrb(t_list **stack_b, int b)
{
	t_list *last = *stack_b;
	t_list *b_last;
	
	if (!(*stack_b))
		return;
	while (last->next)
	{
		b_last = last;
		last = last->next;
	}
	b_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (b)
		ft_putstr_fd("rrb\n", 1);
	return;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_putstr_fd("rrr\n", 1);
}

void pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head = *stack_b;

	if (!(*stack_b))
		return;
	ft_lstadd_front(stack_a, ft_lst_new(head->content));
	(*stack_a)->index = (*stack_b)->index;
	*stack_b = (*stack_b)->next;
	free(head);
	ft_putstr_fd("pa\n", 1);
	return;
}

void pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head = *stack_a;

	if (!(*stack_a))
		return;
	head = *stack_a;
	ft_lstadd_front(stack_b, ft_lst_new(head->content));
	(*stack_b)->index = head->index;
	*stack_a = (*stack_a)->next;
	free(head);
	ft_putstr_fd("pb\n", 1);
	return;
}