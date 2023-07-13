#include "philo.h"

void *ft_routine(void *arg);
static void ft_task(t_thread_args *philosopher);

void *ft_routine(void *arg)
{    
    t_thread_args *philosopher;
    uint32_t n_meal;

    philosopher = arg;
    if (philosopher->container->n_meal_till_full != NULL)
    {
        n_meal = 1;
        while (n_meal++ <= *philosopher->container->n_meal_till_full && philosopher->container->is_a_philo_dead == false)
            ft_task(philosopher);
    }
    else
        while (true && philosopher->container->is_a_philo_dead == false)
            ft_task(philosopher);
    return (NULL);
}

void ft_task(t_thread_args *philosopher)
{
    ft_eat(philosopher);
    ft_think(philosopher);
    ft_sleep(philosopher);
}