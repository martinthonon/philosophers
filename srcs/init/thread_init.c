#include "philo.h"

bool ft_thread_init(t_dllist *container, t_thread_infos **philosopher)
{
    *philosopher = malloc(sizeof(t_thread_infos) * container->size + 1); //size + 2 ?
    if (*philosopher == NULL)
        return (true);
    philosopher[container->size + 1] = NULL;
    return (false);
}