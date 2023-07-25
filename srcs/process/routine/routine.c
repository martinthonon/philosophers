#include "philo.h"

void *ft_routine(void *arg);
static void ft_task(t_thread_args *philosopher);
static void ft_eat(t_thread_args *philosopher);
static void ft_sleep(t_thread_args *philosopher);
static void ft_think(t_thread_args *philosopher);

void *ft_routine(void *arg)
{    
    t_thread_args *philosopher;
    uint32_t n_meal;

    philosopher = arg;
    if (philosopher->container->n_meal_till_full != NO_MEAL)
    {
        n_meal = 1;
        while (n_meal++ <= philosopher->container->n_meal_till_full) //maybe 1 check here for atomic die instead of multi check ?
            ft_task(philosopher);
    }
    else
        while (true)
            ft_task(philosopher);
    return (NULL);
}

static void ft_task(t_thread_args *philosopher)
{
    ft_eat(philosopher);
    ft_sleep(philosopher);
    ft_think(philosopher);
}

static void ft_eat(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == false)
    {
    }
    else
        return (true);
}

static void ft_sleep(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == false)
    {
    }
    else
        return (true);
}

static void ft_think(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == false)
    {
    }
    else
        return (true);
}
