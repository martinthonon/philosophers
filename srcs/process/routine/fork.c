#include "philo.h"

bool ft_take_fork(t_thread_args *philosopher);
bool ft_put_fork(t_thread_args *philosopher);


bool ft_take_fork(t_thread_args *philosopher)
{
    (void)philosopher;
    printf("test\n");
    //pthread_mutex_lock(&philosopher->container->n_fork[philosopher->node->index]);
    return (false);
}

bool ft_put_fork(t_thread_args *philosopher)
{
    (void)philosopher;
    return (false);
}