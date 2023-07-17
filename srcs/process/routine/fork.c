#include "philo.h"

bool ft_take_fork(t_thread_args *philosopher);
bool ft_put_fork(t_thread_args *philosopher);


bool ft_take_fork(t_thread_args *philosopher)
{
    philosopher->node->time_till_last_meal = ft_get_time_ms();
    if (((philosopher->node->index) & 1) == 1)
        usleep(3000);
    return (false);
}

bool ft_put_fork(t_thread_args *philosopher)
{
    (void)philosopher;
    return (false);
}