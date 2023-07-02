#include "philo.h"

void *ft_routine(void *arg);

void *ft_routine(void *arg)
{
    t_thread_args *philosopher = arg;
    uint32_t n_meal;

    n_meal = 1;
    while (n_meal++ <= *philosopher->container->n_meal_till_full)
    {
        printf("pilosopher n °%zu\n", philosopher->node->index);
        ft_think(philosopher);
        ft_eat(philosopher);
        ft_sleep(philosopher);
    }
    return (NULL);
}