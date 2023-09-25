#include "philo.h"

bool			ft_sub_routine(t_dllist *container, t_thread_args *philosopher);
static	bool	ft_thread_go(t_dllist *container, t_thread_args *philosopher);
static	bool	ft_thread_join(t_thread_args *philosopher, size_t size);

bool ft_sub_routine(t_dllist *container, t_thread_args *philosopher)
{
	if (ft_thread_go(container, philosopher) == true)
		return (true);
	ft_is_starving();
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
		if (pthread_create(&philosopher[i].thread_id, NULL, ft_routine, pthread_arg) != CREATED)
		{
			ft_thread_join(philosopher, i);
			return (true);
		}
		++i;
		node = node->next;
	}
	return (false);
}

static bool ft_is_dead(t_dllist *container)
{
	t_dllist_node	*node;

	node = container->sentinel_node->next;
	while (true)
	{
		if (node->node_type != SENTINEL_NODE)
			if (ft_diff_time_ms(node->time_till_last_meal, container->time_to_die) == true)
			{
				container->is_dead = true;
				printf("is dead");
			}
		node = node->next;
	}
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