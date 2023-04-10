#include "push_swap.h"

void	index_list(t_list **stack_a)
{
	t_list *head = *stack_a;
	t_list *tmp = *stack_a;
	int max = 0;
	int i = ft_lstsize(head);
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

void push_to_b(t_list **stack_a, t_list **stack_b)
{
	int stack_size;
	int chunk_start = 0;
	int chunk_end;
	chunk_start = 0;
	chunk_end = ft_lstsize(*stack_a) / 5 - 1;
	int a = 5;
	while (a--)
	{
		stack_size = ft_lstsize(*stack_a);
		while (stack_size--)
		{
				if ((*stack_a)->index >= chunk_start && (*stack_a)->index <= chunk_end)
				{
					if ((*stack_a)->index > (chunk_end + chunk_start)/2)
					{
						pb(stack_a, stack_b);
						rb(stack_b, 1);
					}
					else
						pb(stack_a, stack_b);
				}
				else
					ra(stack_a, 1);
		}
			chunk_start += ft_lstsize(*stack_a) / 5 - 1;
			chunk_end += ft_lstsize(*stack_a) / 5 - 1;
	}
}

void sort_3_nums(t_list **stack_a,	t_list **stack_b)
{
	t_list *head;
	int i = ft_lstsize(*stack_a);
	index_list(stack_a);
	push_to_b(stack_a, stack_b);

}
