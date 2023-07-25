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
        philosopher->node->time_till_last_meal = ft_get_time_ms();
        if (0)
        {
            philosopher->container->is_dead = true;
            ft_atomic_print(philosopher, DEAD);
        }
        else
        {
            ft_atomic_print(philosopher, EATING);
            usleep(philosopher->container->time_to_eat * 1000);
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
        if (0) //change this
        {
            //usleep till die
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
        //if philo is going to die
            //usleep(till die)
            //set dead to true
            //ret true ?
        if (0) //change this
        {
            //usleep till die
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
