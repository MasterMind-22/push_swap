#include "push_swap.h"

void is_instuc_valid(t_list **stack_a, t_list **stack_b, char *instruction)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		sa(*stack_a, 0);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		sb(*stack_b, 0);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss(*stack_a, *stack_b, 0);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else
		ft_error();
}

int is_lst_sorted(t_list *stack_a)
{
	int i;
	t_list *head;

	head = stack_a;
	i = 1;
	if (ft_lstsize(stack_a) == 1)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->content < stack_a->next->content)
			i++;
		stack_a = stack_a->next;
	}
	if (i == ft_lstsize(head))
		return (1);
	else
		return (0);
	
}

int main(int ac, char **av)
{
	char	**args;
	char	*instruction;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*free_lst;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		args = parsing(av, 1);
		add_to_list(&stack_a, args);
		free_arr((char **)args);
		while (1)
		{
			instruction = get_next_line(0);
			if (!instruction)
				break;
			is_instuc_valid(&stack_a, &stack_b, instruction);
			free(instruction);
		}
		if (is_lst_sorted(stack_a) && !ft_lstsize(stack_b))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		while (stack_a)
		{
			free_lst = stack_a;
			stack_a = stack_a->next;
			free(free_lst);
		}
	}
}