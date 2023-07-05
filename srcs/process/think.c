#include "philo.h"

void ft_think(t_thread_args *philosopher);

void ft_think(t_thread_args *philosopher)
{
    philosopher->node->status = thinking;
    printf("It is %ld and pilosopher n °%zu is thinking\n", ft_get_time(), philosopher->node->index);
}