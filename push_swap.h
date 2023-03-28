#ifndef PUSH_SWAP_H_
#define PUSH_SWAP_H_

#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

/*==================== Lists utils ====================*/

int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lst_new(void *content);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);

/*==================== Push_swap utils ====================*/

void	ft_error(void);
int		ft_atoi(const char *str);
void	check_dups(char **av);
void	check_empty(char *str);
void	parsing(char **av);
void    is_sorted(char  **str);
int    args_count(char **av);

#endif