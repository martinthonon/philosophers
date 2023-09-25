#include "philo.h"

void ft_atomic_print(t_thread_args *philosopher, char *status);

void ft_atomic_print(t_thread_args *philosopher, char *status)
{
    pthread_mutex_lock(&philosopher->container->lock_print);
    if (philosopher->container->is_dead == false)
        printf("%llu %zu %s\n", ft_get_time_ms() - philosopher->container->time_start, philosopher->node->index, status);
    pthread_mutex_unlock(&philosopher->container->lock_print);
}