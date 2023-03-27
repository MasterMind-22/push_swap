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



int main()
{
	t_list *new = ft_lst_new("hello");
	t_list *new1 = ft_lst_new(" world");
	t_list *new3 = ft_lst_new("!!");
	ft_lstadd_back(&new, new1);
	ft_lstadd_back(&new1, new3);
	while (new)
	{
		printf("%s", new->content);
		new = new->next;
	}
	
}