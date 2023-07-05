#include "philo.h"

void ft_eat(t_thread_args *philosopher);

void ft_eat(t_thread_args *philosopher)
{
    printf("It is %ld and pilosopher n °%zu is thinking\n", ft_get_time(), philosopher->node->index);
}