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
	int i = ft_lstsize(head);
	head = (*stack_a);
	index_list(&head);
	pb(stack_a, stack_b);
	head = (*stack_a);

	while(head)
	{
		pb(stack_a, stack_b);
		if (head->index < head->next->index)
			pb((stack_a), stack_b);
		else
		{
			ra((stack_a), 1);
			if ((*stack_b)->index > (*stack_a)->index)
			{
				pb((stack_a), stack_b);
				rb(stack_b, 1);
			}
			else
				pb((stack_a), stack_b);

		}
		head = head->next;
	}
}
