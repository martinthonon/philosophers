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
    if ((philosopher->node->index & 1) == 0)
        ft_usleep(philosopher->container->time_to_eat / 2);
    philosopher->node->time_till_last_meal = ft_get_time_ms();
    if (philosopher->container->n_meal_till_full > 0)
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
        pthread_mutex_lock(&philosopher->container->n_fork[philosopher->node->index]);
        ft_atomic_print(philosopher, FORK);
        pthread_mutex_lock(&philosopher->container->n_fork[philosopher->node->index + 1]);
        ft_atomic_print(philosopher, FORK);
        if (ft_timeout(philosopher, philosopher->container->time_to_eat) == true) 
        {
            ft_usleep(ft_time_left_to_die(philosopher));
            //pthread_mutex_lock(&philosopher->container->cool_down);
            if (philosopher->container->is_dead == false)
            {
                philosopher->container->is_dead = true;
                ft_atomic_print(philosopher, DEAD);
            }
            //pthread_mutex_unlock(&philosopher->container->cool_down);
            return (true);
        }
        else
        {
            ft_atomic_print(philosopher, EATING);
            philosopher->node->time_till_last_meal = ft_get_time_ms();
            ft_usleep(philosopher->container->time_to_eat);
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
        if (ft_timeout(philosopher, philosopher->container->time_to_sleep) == true)
        {
            ft_usleep(ft_time_left_to_die(philosopher));
            //pthread_mutex_lock(&philosopher->container->cool_down);
            if (philosopher->container->is_dead == false)
            {
                philosopher->container->is_dead = true;
                ft_atomic_print(philosopher, DEAD);
            }
            //pthread_mutex_unlock(&philosopher->container->cool_down);
            return (true);
        }
        else
        {
            pthread_mutex_unlock(&philosopher->container->n_fork[philosopher->node->index]); //take fork after sleeping
            pthread_mutex_unlock(&philosopher->container->n_fork[philosopher->node->index + 1]);
            ft_atomic_print(philosopher, SLEEPING);
            ft_usleep(philosopher->container->time_to_sleep);
        }
        // pthread_mutex_unlock(&philosopher->container->n_fork[philosopher->node->index]); //take fork after sleeping
        // pthread_mutex_unlock(&philosopher->container->n_fork[philosopher->node->index + 1]);
    }
    else
        return (true);
    return (false);
}

static bool ft_think(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == false)
            ft_atomic_print(philosopher, THINKING);
    else
        return (true); 
    return (false);
}