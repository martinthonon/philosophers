#include "philo.h"

bool			ft_sub_routine(t_dllist *container, t_thread_args *philosopher);
static	bool	ft_thread_go(t_dllist *container, t_thread_args *philosopher);
static	bool	ft_thread_join(t_thread_args *philosopher, size_t size);

bool ft_sub_routine(t_dllist *container, t_thread_args *philosopher)
{
	if (ft_thread_go(container, philosopher) == true)
		return (true);
	if (ft_thread_join(philosopher, container->size) == true)
		return (true);
	return (false);
}

static	bool	ft_thread_go(t_dllist *container, t_thread_args *philosopher)
{
	t_thread_args	*pthread_arg;
	t_dllist_node	*node;
	size_t			i;

	container->time_start = ft_get_time_ms();
	node = container->sentinel_node->next;
	i = 0;
	while (i < container->size)
	{
		pthread_arg = ft_thread_init(container, &philosopher[i], node);
		if (pthread_create(&philosopher[i++].thread_id, NULL, ft_routine, pthread_arg) != CREATED)
			return (true);
		node = node->next;
	}
	return (false);
}

static bool ft_thread_join(t_thread_args *philosopher, size_t size)
{
	size_t i;
	
	i = 0;
	while (i < size)
		if (pthread_join(philosopher[i++].thread_id, NULL) != JOINED)
			return (true);
	return (false);
}