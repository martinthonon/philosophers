#include "philo.h"

void *ft_routine(void *arg);
static void ft_eat(t_thread_args *philosopher);
static void ft_sleep(t_thread_args *philosopher);

void *ft_routine(void *arg)
{    
    t_thread_args *philosopher;

    philosopher = arg;
    philosopher->node->left_fork = &philosopher->container->n_fork[philosopher->node->index % philosopher->container->size];
    philosopher->node->right_fork = &philosopher->container->n_fork[(philosopher->node->index - 1) % philosopher->container->size];
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

static void ft_eat(t_thread_args *philosopher)
{
    ft_atomic_print(philosopher, EATING);
    philosopher->node->time_till_last_meal = ft_get_time_ms();
    printf("%d\n", philosopher->container->time_to_eat);
    ft_usleep(philosopher->container->time_to_eat);
}

static void ft_sleep(t_thread_args *philosopher)
{
    printf("test\n");
    ft_atomic_print(philosopher, SLEEPING);
    ft_usleep(philosopher->container->time_to_sleep);
}