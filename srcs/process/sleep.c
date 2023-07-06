#include "philo.h"

void ft_sleep(t_thread_args *philosopher);

void ft_sleep(t_thread_args *philosopher)
{
   usleep(philosopher->container->time_to_die);
   printf("It is %llu and pilosopher n °%zu is thinking\n", ft_get_time_ms(), philosopher->node->index);
}