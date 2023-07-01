#include "philo.h"

void *ft_routine(void *arg);

void *ft_routine(void *arg)
{
    t_thread_infos *philosopher = arg;
    for (int i = 0; i < 3; ++i)
    {
        printf("I'm the philo n °%zu, and I print %d\n", philosopher->node->index, i);
    }
    return (NULL);
}