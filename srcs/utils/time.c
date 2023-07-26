#include "philo.h"

uint64_t ft_get_time_ms(void);
bool ft_diff_time_ms(uint64_t start_time, uint64_t diff_time);

uint64_t ft_get_time_ms(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((uint64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

bool ft_diff_time_ms(uint64_t start_time, uint64_t diff_time)
{
    if (start_time + diff_time < ft_get_time_ms()) //diff ? t_die - t_eat
        return (true);
    return (false);
}

bool ft_will_die