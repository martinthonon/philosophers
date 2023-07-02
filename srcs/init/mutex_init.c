#include "philo.h"

bool ft_mutex_init(size_t size, pthread_mutex_t *fork);
bool ft_mutex_destroy(size_t size, pthread_mutex_t *fork);

bool ft_mutex_init(size_t size, pthread_mutex_t *fork)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        if (pthread_mutex_init(&fork[i++], NULL) != 0)
            return (true);
    }
    return (false);
}

bool ft_mutex_destroy(size_t size, pthread_mutex_t *fork)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        if (pthread_mutex_destroy(&fork[i++]) != 0)
            return (true);
    }
    return (false);
}