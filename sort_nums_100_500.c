#include "push_swap.h"

void	index_list_min_to_max(t_list **stack_a)
{
	t_list *head;
	t_list *tmp;
	int i;

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

void mini_push_to_b(t_list **stack_a, t_list **stack_b, int *stop, int *chunk_start, int *chunk_end)
{
	if ((*stack_a)->index >= (*chunk_start) && (*stack_a)->index <= *chunk_end)
	{
		if ((*stack_a)->index > ((*chunk_end) + (*chunk_start))/2)
		{
			pb(stack_a, stack_b);
			(*stop)++;
			if (*stack_a && !((*stack_a)->index >= (*chunk_start) && (*stack_a)->index <= (*chunk_end)))
				rr(stack_a, stack_b);
			else
				rb(stack_b, 1);
		}
		else
		{
			pb(stack_a, stack_b);
			(*stop)++;
		}
	}
	else if (*stop <= *chunk_end)
		ra(stack_a, 1);
}


void push_to_b(t_list **stack_a, t_list **stack_b, int d)
{
	int stack_size;
	int chunk_start;
	int chunk_end;
	int a;
	int stop;
	int tmp;

	stop = 0;
	chunk_start = 0;
	chunk_end = ft_lstsize(*stack_a) / d - 1;
	tmp = chunk_end;
	a = ft_lstsize(*stack_a);
	while (a--)
	{
		stack_size = ft_lstsize(*stack_a);
		while (stack_size--)
			mini_push_to_b(stack_a, stack_b, &stop, &chunk_start, &chunk_end);
		chunk_start += tmp;
		chunk_end += tmp;
	}
}

void get_list_max(t_list *stack_b, t_list **max, t_list **bef_max)
{
	t_list *head;
	int b_max;
	int b_bef_max;
	int i;

	b_max = INT_MIN;
	b_bef_max = INT_MIN;
	i = ft_lstsize(stack_b);
	head = stack_b;
	while (i--)
	{
		if (head->content > b_max)
		{
			*bef_max = *max;
			b_bef_max = b_max;
			*max = head;
			b_max = (*max)->content;
		}
		if (head->content < b_max && head->content > b_bef_max)
			*bef_max = head;
		head = head->next;
	}
}

void	whois_first(t_list **stack_a, t_list **stack_b)
{
	t_list	*max;
	t_list	*bef_max;

	get_list_max(*stack_b, &max, &bef_max);
	index_list(*stack_b);

	if ((*stack_b) == bef_max)
		pa(stack_a, stack_b);
	if (max->moves >= ft_lstsize(*stack_b) / 2)
		while (*stack_b != max)
			rrb(stack_b, 1);
	else if (max->moves < ft_lstsize(*stack_b) / 2)
		while (*stack_b != max)
			rb(stack_b, 1);
	if ((*stack_b) == max)
		pa(stack_a, stack_b);
	return;
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b))
	{
		whois_first(stack_a, stack_b);
		if (*stack_a && (*stack_a)->next && (*stack_a)->content > (*stack_a)->next->content)
			sa(*stack_a, 1);
	}
	return ;
}
