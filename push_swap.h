#ifndef PUSH_SWAP_H_
#define PUSH_SWAP_H_

#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "./libft/libft.h"

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;


void	ft_error(void);
int		ft_atoi(const char *str);
void	check_dups(char **av);
void	check_empty(char *str);
void	parsing(char **av);


#endif