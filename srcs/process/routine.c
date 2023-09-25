#include "philo.h"

void *ft_routine(void *arg);
static bool ft_eat(t_thread_args *philosopher);
static bool ft_sleep(t_thread_args *philosopher);

void *ft_routine(void *arg)
{    
    t_thread_args *philosopher;

    philosopher = arg;
    if ((philosopher->node->index & 1) == 0)
        ft_usleep(philosopher->container->time_to_eat / 2);
    philosopher->node->time_till_last_meal = ft_get_time_ms();
    while (!philosopher->container->is_dead)
    {
        ft_atomic_print(philosopher, THINKING);
        ft_eat(philosopher);
        ft_sleep(philosopher);
    }
    return (NULL);
}

static bool ft_eat(t_thread_args *philosopher)
{
    ft_atomic_print(philosopher, EATING);
    philosopher->node->time_till_last_meal = ft_get_time_ms();
    ft_usleep(philosopher->container->time_to_eat);
    return (false);
}

static bool ft_sleep(t_thread_args *philosopher)
{
    ft_usleep(philosopher->container->time_to_sleep);
    return (false);
}