#include "push_swap.h"

// void fun()
// {
//     system("leaks push_swap");
// }

int main(int ac, char **av)
{
    // atexit(fun);
    if (ac > 1)
    {
        parsing(av);
        // while(1)
    }
    else
        ft_error();
    return(0);
}