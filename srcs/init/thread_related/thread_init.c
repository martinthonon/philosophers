#include "philo.h"

bool ft_thread_create(size_t size, t_thread_args **philosopher);
t_thread_args ft_thread_init(t_dllist *container, t_thread_args philosopher, t_dllist_node *node);

bool ft_thread_create(size_t size, t_thread_args **philosopher)
{
    *philosopher = malloc(sizeof(t_thread_args) * size);
    if (*philosopher == NULL)
        return (true);
    return (false);
}

t_thread_args ft_thread_init(t_dllist *container, t_thread_args philosopher, t_dllist_node *node)
{
    philosopher.container = container;
    philosopher.node = node;
    return (philosopher);
}