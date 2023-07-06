#include "philo.h"

void ft_think(t_thread_args *philosopher);

void ft_think(t_thread_args *philosopher)
{
    philosopher->node->status = thinking;
    printf("It is %llu and pilosopher n °%zu is thinking\n", ft_get_time_ms(), philosopher->node->index);
}