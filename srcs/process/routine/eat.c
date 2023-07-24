#include "philo.h"

void ft_eat(t_thread_args *philosopher);

void ft_eat(t_thread_args *philosopher)
{
    // if (pthread_mutex_init(&philosopher->container->n_fork[0], NULL) != 0)
    //     printf("error\n");
    printf("-->%p\n", &philosopher->container->lock_print);
    //pthread_mutex_init(&philosopher->container->lock_print, NULL);
    pthread_mutex_lock(&philosopher->container->lock_print);
    printf("->I'm philo n %zu\n", philosopher->node->index);
    //pthread_mutex_lock(&philosopher->container->lock_print);
    //printf("I'm philo n %zu\n", philosopher->node->index);
    //usleep(5000000);
    //pthread_mutex_unlock(&philosopher->container->n_fork[0]);
    //pthread_mutex_unlock(&philosopher->container->lock_print);
    //printf("It is %lu and pilosopher n °%zu is eating\n", ft_get_time_ms(), philosopher->node->index);
}