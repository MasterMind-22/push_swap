#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("\033[1;31mError\n\033[0m", 2);
	exit(1);
}

int    args_count(char **av)
{
    int i = 0;
    while (av[i])
        i++;
    return(i);
}
