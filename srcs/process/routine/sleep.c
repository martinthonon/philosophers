#include "philo.h"

void ft_sleep(t_thread_args *philosopher);

void ft_sleep(t_thread_args *philosopher)
{
   usleep(5000000);
   printf("It is %lu and pilosopher n °%zu is sleeping\n", ft_get_time_ms(), philosopher->node->index);
}