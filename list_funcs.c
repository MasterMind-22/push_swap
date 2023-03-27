#include "push_swap.h"

t_list	*ft_lst_new(void *content)
{
	t_list *head;
	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;
	if (!(*lst))
	{
		*lst = new;
		return;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
    new->next = *lst;
    *lst = new;
}

t_list *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    return (lst);
}

int ft_lstsize(t_list *lst)
{
    int counter;

    counter = 0;
    while (lst != NULL)
    {
        lst = lst->next;
        counter++;
    }
    return(counter);
}
