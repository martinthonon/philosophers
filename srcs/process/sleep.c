#include "philo.h"

void ft_sleep(t_thread_args *philosopher);

void ft_sleep(t_thread_args *philosopher)
{
   printf("pilosopher n °%zu is sleeping\n", philosopher->node->index); 
}