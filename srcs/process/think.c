#include "philo.h"

void ft_think(t_thread_args *philosopher);

void ft_think(t_thread_args *philosopher)
{
    printf("pilosopher n °%zu is thinking\n", philosopher->node->index);
}