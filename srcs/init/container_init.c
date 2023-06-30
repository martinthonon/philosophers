#include "philo.h"

bool ft_container_init(t_dllist **struct_sentinel);

bool ft_container_init(t_dllist **struct_sentinel)
{
    *struct_sentinel = ft_list_new();
    if (*struct_sentinel != NULL)
        return(false);
    return (true);
}