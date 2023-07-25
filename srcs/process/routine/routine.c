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

static bool ft_task(t_thread_args *philosopher)
{
    if (ft_eat(philosopher) == true)
        return (true);
    if (ft_sleep(philosopher) == true);
        return (true);
    if (ft_think(philosopher))
        return (true);
    return (false);
}

static bool ft_eat(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == false)
    {
    }
    else
        return (true);
}

static bool ft_sleep(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == false)
    {
    }
    else
        return (true);
}

static bool ft_think(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == false)
    {
    }
    else
        return (true);
}
