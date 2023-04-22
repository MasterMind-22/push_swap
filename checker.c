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
		rr(stack_a, stack_b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss(*stack_a, *stack_b);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
}


int main(int ac, char **av)
{
	char	**args;
	char	*instruction;
	t_list	*stack_a;
	t_list	*stack_b;
	// t_list	*free_lst;

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
			is_instuc_valid(&stack_a, &stack_b, instruction);
			free(instruction);
		}
		









		// while (stack_a)
		// {
		// 	free_lst = stack_a;
		// 	stack_a = stack_a->next;
		// 	free(free_lst);
		// }
	}
}