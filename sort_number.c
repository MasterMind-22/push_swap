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



void sort_3_nums(t_list **stack_a,	t_list **stack_b)
{
	t_list *head = (*stack_a);
	index_list(stack_a);
	int i = ft_lstsize(*stack_a);
	while (i--)
	{
		head = *stack_a;
		while ((*stack_a)->next)
		{
			if ((*stack_a)->index > (*stack_a)->next->index)
				pb(stack_a, stack_b);
			else if ((*stack_a)->index < (*stack_a)->next->index)
			{
				ra(stack_a, 1);
				// break;
			}
			(*stack_a) = (*stack_a)->next;
		}
	}
}
