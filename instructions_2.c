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
