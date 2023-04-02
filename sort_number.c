#include "push_swap.h"

 t_list	*lst_max(t_list **stack_a)
 {
	int max = 0;
	t_list *tmp;

	while (*stack_a)
	{
		if ((*stack_a)->content > max)
		{
			max = (*stack_a)->content;
			tmp = *stack_a;
		}
		(*stack_a) = (*stack_a)->next;
	}
	// printf("here\n");
	// printf("|| %d ||\n\n", max);
	return(tmp);
	
 }

 void	index_list(t_list **stack_a)
 {
	t_list *head = *stack_a;
	t_list *tmp;
	t_list *prev_tmp = NULL;
	int i = ft_lstsize(head);
	while (i--)
	{
		head = *stack_a;
		printf("|| %d ||\n", head->index);
		// lst_max(&head)->index = i;
		if ((lst_max(&head)->index) == -1 || lst_max(&head) != prev_tmp)
			lst_max(&head)->index = i;
		prev_tmp = head;
	}
		printf("|| %d ||\n", prev_tmp->content);
 }


void sort_3_nums(t_list *lst)
{
	index_list(&lst);
// 	while (lst)
// 	{
// 		printf("%d === %d\n", lst->content , lst->index);
// 		// free(lstst);
// 		lst = lst->next;
// 	}
}
