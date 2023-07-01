#include "philo.h"

int main(int argc, char **argv)
{
    t_dllist *container;

    if (argc < 5 || argc > 6)
        return (1);
    if (ft_arg_init(argc, ++argv, &container) == true)
        return (1); 
    if (ft_process(container) == true)
    {
        ft_list_destroy(container);
        return (1);
    }
    ft_list_destroy(container);
    return (0);
}