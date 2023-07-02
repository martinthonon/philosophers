#include "philo.h"

void ft_eat(t_thread_args *philosopher);

void ft_eat(t_thread_args *philosopher)
{
    printf("pilosopher n °%zu is eating\n", philosopher->node->index);
}