#include "philo.h"

void *ft_routine(void *arg);
static void ft_eat(t_thread_args *philosopher);
static void ft_sleep(t_thread_args *philosopher);

void *ft_routine(void *arg)
{    
    t_thread_args *philosopher;

    philosopher = arg;
    if ((philosopher->node->index & 1) == 0)
        ft_usleep(philosopher->container->time_to_eat / 2);
    while (philosopher->container->is_plenty == false && philosopher->container->is_dead == false)
    {
        ft_atomic_print(philosopher, THINKING);
        ft_eat(philosopher);
        ft_sleep(philosopher);
    }
    return (NULL);
}

static void ft_eat(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == true)
        return ;
    pthread_mutex_lock(philosopher->node->left_fork);
    ft_atomic_print(philosopher, FORK);
    pthread_mutex_lock(philosopher->node->right_fork);
    ft_atomic_print(philosopher, FORK);
    ft_atomic_print(philosopher, EATING);
    philosopher->node->time_since_last_meal = ft_get_time_ms();
    if (philosopher->container->n_meal_till_full != NO_MEAL && philosopher->node->n_meal < philosopher->container->n_meal_till_full)
    {
        ++philosopher->node->n_meal;
        if (philosopher->node->n_meal == philosopher->container->n_meal_till_full)
            ++philosopher->container->meal_count;
        if (philosopher->container->meal_count == philosopher->container->size)
            philosopher->container->is_plenty = true;
    }
    ft_usleep(philosopher->container->time_to_eat);
    pthread_mutex_unlock(philosopher->node->right_fork);
    pthread_mutex_unlock(philosopher->node->left_fork);
}

static void ft_sleep(t_thread_args *philosopher)
{
    if (philosopher->container->is_dead == true)
        return ;
    ft_atomic_print(philosopher, SLEEPING);
    ft_usleep(philosopher->container->time_to_sleep);
}