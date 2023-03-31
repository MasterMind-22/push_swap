#include "push_swap.h"

void sort_3_nums(t_list *lst)
{
	// t_list *lst = lst;
	if (lst->content > lst->next->content)
		sa(lst, 1);
	if (lst->next->content > lst->next->next->content)
	{
		rra(&lst, 1);
		// sa(lst, 1);
	}
}