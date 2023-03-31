#include "push_swap.h"

void sa(t_list *stack_a, int a)
{
	int	tmp;

	tmp = stack_a->next->content;
	stack_a->next->content = stack_a->content;
	stack_a->content = tmp;
	if (a)
		ft_putstr_fd("sa\n", 1);
}

void sb(t_list *stack_b, int b)
{
	int tmp;

	tmp = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = tmp;
	if (b)
		ft_putstr_fd("sb\n", 1);
}

void ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_putstr_fd("ss\n", 1);
}

void ra(t_list *stack_a, int a)
{
	int	tmp;
	t_list	*head;

	head = stack_a;
	tmp = head->content;
	while (head->next)
		head = head->next;
	stack_a->content = head->content;
	head->content = tmp;
	if (a)
		ft_putstr_fd("ra\n", 1);
}

void rb(t_list *stack_b, int a)
{
	int	tmp;
	t_list	*head;

	head = stack_b;
	tmp = head->content;
	while (head->next)
		head = head->next;
	stack_b->content = head->content;
	head->content = tmp;
	if (a)
		ft_putstr_fd("rb\n", 1);
}

void rr(t_list *stack_a, t_list *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
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
	t_list	*head = *stack_a;

	ft_lstadd_front(stack_b, ft_lst_new(head->content));
	*stack_a = (*stack_a)->next;
	free(head);
	ft_putstr_fd("pa\n", 1);
}

void pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head = *stack_b;

	ft_lstadd_front(stack_a, ft_lst_new(head->content));
	*stack_b = (*stack_b)->next;
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
// 	// t_list *stack_a =		 ft_lst_new(1);
// 	// ft_lstadd_back(&stack_a, ft_lst_new(2));
// 	// ft_lstadd_back(&stack_a, ft_lst_new(3));
// 	// ft_lstadd_back(&stack_a, ft_lst_new(4));
// 	// ft_lstadd_back(&stack_a, ft_lst_new(4));
// 	rrb(&stack_b, 2);
// 	// rra(&stack_a, 2);
// 	// pb(&stack_a, &stack_b);
// 	while (stack_b)
// 	{
// 		printf("%d ", stack_b->content);
// 		stack_b = stack_b->next;
// 	}
// 	// printf("\n=========================\n");
// 	// while (stack_a)
// 	// {
// 	// 	printf("%d ", stack_a->content);
// 	// 	stack_a = stack_a->next;
// 	// }
// }