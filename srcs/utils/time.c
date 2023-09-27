#include "philo.h"

uint64_t ft_get_time_ms(void);
bool ft_diff_time_ms(uint64_t start_time, uint64_t diff_time); //used ?
void	ft_usleep(uint64_t ms);

uint64_t ft_get_time_ms(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((uint64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

bool ft_diff_time_ms(uint64_t start_time, uint64_t diff_time)
{
    //printf("--> %llu, --> %llu\n", start_time + diff_time, ft_get_time_ms());
    if (start_time + diff_time < ft_get_time_ms())
        return (true);
    return (false);
}

void	ft_usleep(uint64_t ms)
{
	const uint64_t start = ft_get_time_ms();
	while (ft_get_time_ms() - start < ms)
		usleep(100);
}
