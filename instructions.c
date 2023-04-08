#include "push_swap.h"

void sa(t_list *stack_a, int a)
{
	int	tmp;
	int	index;

	tmp = stack_a->next->content;
	index = stack_a->next->index;
	stack_a->next->content = stack_a->content;
	stack_a->next->index = stack_a->index;
	stack_a->content = tmp;
	stack_a->index = index;
	if (a)
		ft_putstr_fd("sa\n", 1);
}

void sb(t_list *stack_b, int b)
{
	int	tmp;
	int	index;

	tmp = stack_b->next->content;
	index = stack_b->next->index;
	stack_b->next->content = stack_b->content;
	stack_b->next->index = stack_b->index;
	stack_b->content = tmp;
	stack_b->index = index;
	if (b)
		ft_putstr_fd("sb\n", 1);
}

void ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_putstr_fd("ss\n", 1);
}

void ra(t_list **stack_a, int a)
{
	int		tmp;
	t_list	*head;

	head = *stack_a;
	ft_lstadd_back(stack_a, ft_lst_new(head->content));
	ft_lstlast(head)->index = (head)->index;
	(*stack_a) = (*stack_a)->next;
	free(head);
	if (a)
		ft_putstr_fd("ra\n", 1);
}

void rb(t_list **stack_b, int a)
{
	int		tmp;
	t_list	*head;

	head = *stack_b;
	ft_lstadd_back(stack_b, ft_lst_new(head->content));
	ft_lstlast(head)->index = (head)->index;
	(*stack_b) = (*stack_b)->next;
	free(head);
	if (a)
		ft_putstr_fd("rb\n", 1);
}

void rr(t_list *stack_a, t_list *stack_b)
{
	ra(&stack_a, 0);
	rb(&stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}

void rra(t_list **stack_a, int a)
{
	t_list *last = *stack_a;
	t_list *b_last = NULL;

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
}

void rrb(t_list **stack_b, int b)
{
	t_list *last = *stack_b;
	t_list *b_last = NULL;

	while (last->next)
	{
		b_last = last;
		last = last->next;
	}
	last->next = *stack_b;
	b_last->next = NULL;
	*stack_b = last;
	if (b)
		ft_putstr_fd("rrb\n", 1);
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

	ft_lstadd_front(stack_a, ft_lst_new(head->content));
	(*stack_a)->index = (*stack_b)->index;
	*stack_b = (*stack_b)->next;
	free(head);
	ft_putstr_fd("pa\n", 1);
}

void pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head = *stack_a;

	ft_lstadd_front(stack_b, ft_lst_new(head->content));
	(*stack_b)->index = head->index;
	*stack_a = (*stack_a)->next;
	free(head);
	ft_putstr_fd("pb\n", 1);
}





// int main()
// {
// 	t_list *stack_b =		 ft_lst_new(5);
// 	ft_lstadd_back(&stack_b, ft_lst_new(4));
// 	ft_lstadd_back(&stack_b, ft_lst_new(3));
// 	ft_lstadd_back(&stack_b, ft_lst_new(2));
// 	ft_lstadd_back(&stack_b, ft_lst_new(1));
// 	t_list *stack_a =		 ft_lst_new(1);
// 	ft_lstadd_back(&stack_a, ft_lst_new(2));
// 	ft_lstadd_back(&stack_a, ft_lst_new(3));
// 	ft_lstadd_back(&stack_a, ft_lst_new(4));
// 	ft_lstadd_back(&stack_a, ft_lst_new(5));
// 	pa(&stack_a, &stack_b);
// 	while (stack_b)
// 	{
// 		printf("%d ", stack_b->content);
// 		stack_b = stack_b->next;
// 	}
// 	printf("\n=========================\na: \n");
// 	while (stack_a)
// 	{
// 		printf("%d ", stack_a->content);
// 		stack_a = stack_a->next;
// 	}
// }