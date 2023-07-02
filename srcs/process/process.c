#include "philo.h"

bool ft_process(t_dllist *container);
static bool ft_thread_start(t_dllist *container, t_thread_args *philosopher, t_dllist_node *node);

bool ft_process(t_dllist *container)
{
    t_thread_args *philosopher;
    size_t i;
    
    if (ft_thread_create(container, &philosopher) == true)
        return (true);
    i = 0;
    while (i < container->size)
    {
        if (pthread_mutex_init(&container->n_fork[i++], NULL) != 0)
        {
            free(philosopher);
            return (true);
        }
    }
    if (ft_thread_start(container, philosopher, container->sentinel_node->next) == true)
    {
        free(philosopher);
        return (true);
    }
    return (false);
}

static bool ft_thread_start(t_dllist *container, t_thread_args *philosopher, t_dllist_node *node)
{
    size_t i;
    void *result;

    i = 0;
    while (i < container->size)
    {
        philosopher[i] = ft_thread_init(container, philosopher[i], node);
        if (pthread_create(&philosopher[i].thread_id, NULL, ft_routine, &philosopher[i]) != 0)
            return (true);
        node = node->next;
        ++i;
    }
    i = 0;
    while (i < container->size)
        if (pthread_join(philosopher[i++].thread_id, &result) != 0)
            return (true);
    return (false);
}
