#include "philo.h"

bool ft_set_mutex(uint8_t flag, t_dllist *container);

bool ft_set_mutex(uint8_t flag, t_dllist *container)
{
    return (ft_mutex_flag(flag, "%m, %m, %M", container->lock_print, \
			container->cool_down, container->n_fork, container->size));
}