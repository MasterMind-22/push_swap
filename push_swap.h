/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:56:13 by yonadry           #+#    #+#             */
/*   Updated: 2023/04/12 16:34:53 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				index;
	int				content;
	int				moves;
	struct s_list	*next;
}	t_list;


/*==================== Lists utils ====================*/

int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lst_new(int num);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
int		ft_strcmp(char *s1, char *s2);

/*==================== Push_swap utils ====================*/

void	ft_error(void);
int		ft_atoi(const char *str);
void	check_dups(char **av);
void	check_empty(char *str);
char	**parsing(char **av);
void	is_sorted(char **str);
int		args_count(char **av);
void	free_arr(void **str);
void	sort_3_nums(t_list **stack_a,	t_list **stack_b);


/*==================== Instructions ====================*/

void	sa(t_list *stack_a, int a);
void	sb(t_list *stack_b, int b);
void	ss(t_list *stack_a, t_list *stack_b);
void	ra(t_list **stack_a, int a);
void	rb(t_list **stack_b, int a);
void	rr(t_list *stack_a, t_list *stack_b);
void	rra(t_list **stack_a, int a);
void	rrb(t_list **stack_b, int b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);




#endif