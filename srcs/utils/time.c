#include "philo.h"

uint64_t ft_get_time_ms(void);
bool ft_diff_time_ms(uint64_t start_time, uint64_t diff_time); //used ?
bool ft_timeout(t_thread_args *philosopher, uint64_t time_till);
uint64_t ft_time_left_to_die(t_thread_args *philosopher);

void	ft_usleep(uint64_t ms);

uint64_t ft_get_time_ms(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((uint64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

bool ft_diff_time_ms(uint64_t start_time, uint64_t diff_time)
{
    if (start_time + diff_time < ft_get_time_ms())
        return (true);
    return (false);
}

bool ft_timeout(t_thread_args *philosopher, uint64_t time_till)
{
    const uint64_t now = ft_get_time_ms();
    uint64_t time_elapsed = now - philosopher->node->time_till_last_meal;
    //printf("-->%llu, %llu\n",philosopher->container->time_to_die + time_elapsed,  time_till + time_elapsed);
    return (philosopher->container->time_to_die + time_elapsed < time_till + time_elapsed);
}



void	ft_usleep(uint64_t ms)
{
	const uint64_t start = ft_get_time_ms();
	while (ft_get_time_ms() - start < ms)
		usleep(100);
}


uint64_t ft_time_left_to_die(t_thread_args *philosopher)
{
    const uint64_t now = ft_get_time_ms();
    uint64_t time_elapsed = now - philosopher->node->time_till_last_meal;
    uint64_t time_left = philosopher->container->time_to_die - time_elapsed;

    return (time_left > 0) ? time_left : 0;
}

