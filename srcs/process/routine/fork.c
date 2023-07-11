#include "philo.h"

bool ft_take_fork(t_thread_args *philosopher);
bool ft_put_fork(t_thread_args *philosopher);


bool ft_take_fork(t_thread_args *philosopher)
{
    philosopher->node->time_till_last_meal = ft_get_time_ms();
    if (((philosopher->node->index) & 1) == 1)
        usleep(3000);
    if (ft_diff_time_ms(philosopher->node->time_till_last_meal, (uint64_t)philosopher->container->time_to_die))
        printf("is dead\n");
    pthread_mutex_lock(&philosopher->container->n_fork[philosopher->node->index]);
    pthread_mutex_lock(&philosopher->container->n_fork[philosopher->node->index + 1]);
    return (false);
}

bool ft_put_fork(t_thread_args *philosopher)
{
    pthread_mutex_unlock(&philosopher->container->n_fork[philosopher->node->index]);
    pthread_mutex_unlock(&philosopher->container->n_fork[philosopher->node->index + 1]);
    return (false);
}