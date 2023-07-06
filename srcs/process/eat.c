#include "philo.h"

void ft_eat(t_thread_args *philosopher);

void ft_eat(t_thread_args *philosopher)
{
    printf("It is %llu and pilosopher n °%zu is thinking\n", ft_get_time_ms(), philosopher->node->index);
}