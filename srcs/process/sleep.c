#include "philo.h"

void ft_sleep(t_thread_args *philosopher);

void ft_sleep(t_thread_args *philosopher)
{
   usleep(philosopher->container->time_to_die);
   printf("It is %ld and pilosopher n °%zu is thinking\n", ft_get_time(), philosopher->node->index);
}