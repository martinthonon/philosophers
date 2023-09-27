#include "philo.h"

bool		ft_sub_routine(t_dllist *container, t_thread_args *philosopher);
static bool	ft_thread_start(t_dllist *container, t_thread_args *philosopher);
static bool	ft_is_starving(t_dllist *container);
static bool	ft_thread_join(t_thread_args *philosopher, ssize_t size);

bool	ft_sub_routine(t_dllist *container, t_thread_args *philosopher)
{
	bool is_starving;
	bool is_join;

	if (ft_thread_start(container, philosopher) == true)
		return (true);
	is_starving = ft_is_starving(container);
	is_join = ft_thread_join(philosopher, container->size);
	return (is_starving || is_join);
}

static bool	ft_thread_start(t_dllist *container, t_thread_args *philosopher)
{
	t_thread_args	*pthread_arg;
	t_dllist_node	*node;
	ssize_t			i;

	container->time_start = ft_get_time_ms();
	node = container->sentinel_node->next;
	i = -1;
	while (++i < container->size)
	{
		pthread_arg = ft_thread_init(container, &philosopher[i], node);
		if (pthread_create(&philosopher[i].thread_id, NULL, ft_routine, pthread_arg) != CREATED)
		{
			ft_thread_join(philosopher, i);
			return (true);
		}
		node = node->next;
	}
	return (false);
}

static bool	ft_is_starving(t_dllist *container)
{
	t_dllist_node	*node;

	node = container->sentinel_node->next;
	while (true) //communication
	{
		if (node->node_type != SENTINEL_NODE)
		{
			if (ft_diff_time_ms(node->time_till_last_meal, container->time_to_die) == true)
			{
				container->is_dead = true;
				printf("%llu %zu %s\n", ft_get_time_ms() - container->time_start, node->index + 1, DEAD);
				return (true);
			}
		}
		node = node->next;
	}
	return (false);
}

static bool	ft_thread_join(t_thread_args *philosopher, ssize_t size)
{
	ssize_t i;

	i = -1;
	while (++i < size)
		if (pthread_join(philosopher[i].thread_id, NULL) != JOINED)
			return (true);
	return (false);
}