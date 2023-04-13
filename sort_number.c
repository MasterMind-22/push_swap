#include "push_swap.h"

void	index_list(t_list **stack_a)
{
	t_list *head = *stack_a;
	t_list *tmp = *stack_a;
	// int max = 0;
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
	int chunk_start;
	int chunk_end;
	int tmp;
	int a;

	chunk_start = 0;
	chunk_end = ft_lstsize(*stack_a) / 5 - 1;
	tmp = chunk_end;
	a = ft_lstsize(*stack_a);
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
		chunk_start += tmp;
		chunk_end += tmp;
	}
}

void get_list_max(t_list *stack_b, t_list **max, t_list **bef_max)
{
	t_list *head;
	int i;

	i = ft_lstsize(stack_b);
	head = stack_b;
	while (i--)
	{
		if (head->content > (*max)->content)
		{
			*bef_max = *max;
			*max = head;
		}
		if (head->content < (*max)->content && head->content > (*bef_max)->content)
			*bef_max = head;
		head = head->next;
	}
}

void count_move_to_head(t_list *stack_a)
{
	int i =1;
	while (stack_a)
	{
		stack_a->moves = i;
		i++;
		stack_a = stack_a->next;
	}
}

void push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*max;
	t_list	*bef_max;
	int i = ft_lstsize(*stack_b);
	max = ft_lst_new(INT_MIN);
	bef_max = ft_lst_new(INT_MIN);
	// (void)stack_a;
	int a= 0;
	while (i--)
	{
		// if (!(*stack_b))
		// 	return;
		a = ft_lstsize(*stack_b);
		while (a--)
		{
			get_list_max(*stack_b, &max, &bef_max);
			count_move_to_head(*stack_b);
			if ((*stack_b) == max)
				pa(stack_a, stack_b);
			else if (*stack_b)
			{
				if (max->moves > ft_lstsize(*stack_b)/2)
					rrb(stack_b, 1);
				else if (max->moves < ft_lstsize(*stack_b)/2)
					rb(stack_b, 1);
				else
					pa(stack_a, stack_b);
					
			}
		}
	}
	return;
}

void sort_3_nums(t_list **stack_a,	t_list **stack_b)
{
	// t_list	*head;
	// int		i;
	// int		stack_size;
	
	index_list(stack_a);
	push_to_b(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
}