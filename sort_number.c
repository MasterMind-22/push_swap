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

int longest_inc_sub(t_list **stack_a)
{
	t_list *head = (*stack_a);
	t_list *head1 = *stack_a;
	t_list *tmp = *stack_a;

	int i = ft_lstsize(head);
	int longg = 1;
	int index;
	while (i--)
	{
		index = 1;
		while (head->next)
		{
			if (head1->content < head->content)
			{
				index++;
				// head1 = head;
				printf("++++++| %d |++++++\n", head1->content);
			}
			head = head->next;
		}
		if (index > longg)
			longg = index;
		// printf("<<<<<< %d >>>>>\n", head1->content);
		head = head1->next;
		head1 = head1->next;
	}
		// printf("%d\n", longg);
	return longg;
}

void sort_3_nums(t_list **stack_a,	t_list **stack_b)
{
	longest_inc_sub(stack_a);
	// t_list *head = (*stack_a);
	// index_list(stack_a);
	// int i = ft_lstsize(*stack_a);
	// while (i--)
	// {
	// 	head = *stack_a;
	// 	while (head)
	// 	{
	// 		if (head->index > head->next->index)
	// 			ra(stack_a, 1);
	// 		else
	// 		{
	// 			ra(stack_a, 1);
	// 			break;
	// 		}
	// 		head = head->next;
	// 	}
	// }
}
