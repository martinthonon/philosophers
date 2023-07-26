#include "philo.h"

void *ft_routine(void *arg);
static bool ft_task(t_thread_args *philosopher);
static bool ft_eat(t_thread_args *philosopher);
static bool ft_sleep(t_thread_args *philosopher);
static bool ft_think(t_thread_args *philosopher);

void *ft_routine(void *arg)
{    
    t_thread_args *philosopher;
    uint32_t n_meal;

    philosopher = arg;
    philosopher->node->time_till_last_meal = ft_get_time_ms();
    if (philosopher->container->n_meal_till_full != NO_MEAL)
    {
        n_meal = 1;
        while (n_meal++ <= philosopher->container->n_meal_till_full)
            if (ft_task(philosopher) == true)
                return (NULL);
    }
    else
        while (true)
            if (ft_task(philosopher) == true)
                return (NULL);
    return (NULL);
}

static bool ft_task(t_thread_args *philosopher)
{
    if (ft_eat(philosopher) == true)
        return (true);
    if (ft_sleep(philosopher) == true)
        return (true);
    if (ft_think(philosopher) == true)
        return (true);
    return (false);
}

static bool ft_eat(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == false)
    {
        if (ft_timeout(philosopher->container->time_to_eat) == true)
        {
            usleep(philosopher->node->slow_death * 1000);
            philosopher->container->is_dead = true;
            ft_atomic_print(philosopher, DEAD);
        }
        else
        {
            ft_atomic_print(philosopher, EATING);
            usleep(philosopher->container->time_to_eat * 1000); //ft_usleep
        }
    }
    else
        return (true);
    return (false);
}

static bool ft_sleep(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == false)
    {
        const uint32_t now = ft_get_time_ms();
        //if (philosopher->container->time_to_die + philosopher->node->time_till_last_meal * philosopher->node->time_till_last_meal - now < philosopher->container->t)
        if (ft_timeout(philosopher->container->time_to_sleep) == true)
        {
            usleep(philosopher->node->slow_death * 1000);
            philosopher->container->is_dead = true;
            ft_atomic_print(philosopher, DEAD);
            return (true);
        }
        else
        {
            ft_atomic_print(philosopher, SLEEPING);
            usleep(philosopher->container->time_to_sleep * 1000);
        }
    }
    else
        return (true);
    return (false);
}

static bool ft_think(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == false)
    {
        if (1)
        {
            //usleep(philosopher->node->slow_death * 1000);
            philosopher->container->is_dead = true;
            ft_atomic_print(philosopher, DEAD);
            return (true);
        }
        else
            ft_atomic_print(philosopher, THINKING);  
    }
    else
        return (true); 
    return (false);
}


// if (last_meal + time_to_eat > last_meal + time_to_die)
//     time_to_eat - time_to_die > 1 ??