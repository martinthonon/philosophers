#include "philo.h"

void *ft_routine(void *arg);
static bool ft_task(t_thread_args *philosopher);
static bool ft_eat(t_thread_args *philosopher);
static bool ft_sleep(t_thread_args *philosopher);

void *ft_routine(void *arg)
{    
    t_thread_args *philosopher;
    uint32_t n_meal;

    philosopher = arg;
    if ((philosopher->node->index & 1) == 0)
        ft_usleep(philosopher->container->time_to_eat / 2);
    philosopher->node->time_till_last_meal = ft_get_time_ms();
    if (philosopher->container->n_meal_till_full > NO_MEAL)
    {
        while (philosopher->node->n_meal < philosopher->container->n_meal_till_full)
            ft_task(philosopher);
                return (NULL);
    }
    else
        while (true)
            ft_task(philosopher); // void ?
                return (NULL);
    return (NULL);
}

static bool ft_task(t_thread_args *philosopher)
{
    ft_atomic_print(philosopher, THINKING);
    ft_eat(philosopher);
    ft_sleep(philosopher);
    return (false);
}

static bool ft_eat(t_thread_args *philosopher)
{
    ft_atomic_print(philosopher, EATING);
    return (false);
}

static bool ft_sleep(t_thread_args *philosopher)
{
    (void)philosopher;
    return (false);
}