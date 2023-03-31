#include "push_swap.h"

void sort_3_nums(t_list *lst)
{
	if (lst->content > lst->next->next->content)
	{
		ra(lst, 1);
		sa(lst, 1);
	}
	else if (lst->content > lst->next->content)
		sa(lst, 1);
	else if (lst->next->content > lst->next->next->content)
	{
		rra(&lst, 1);
		sa(lst, 1);
	}
	while (lst)
	{
		printf("%d\n", lst->content);
		// free(lstst);
		lst = lst->next;
	}
}