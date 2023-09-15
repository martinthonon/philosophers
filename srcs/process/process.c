/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:46:33 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/15 12:55:15 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool		ft_process(t_dllist *container);
static bool	ft_thread_start(t_dllist *container, t_thread_args *philosopher,
				t_dllist_node *node);
static bool	ft_thread_join(t_thread_args *philosopher, size_t size);

bool	ft_process(t_dllist *container)
{
	t_thread_args	*philosopher;

	if (ft_thread_create(container->size, philosopher) == true)
		return (true);
	if (ft_mutex_flag(INIT, "%m, %m, %M", &container->lock_print,
			container->cool_down, container->n_fork, container->size) == true)
		return (free(philosopher), true);
	if (ft_thread_start(container, philosopher,
			container->sentinel_node->next) == true)
		return (free(philosopher), true);
	if (ft_mutex_flag(DESTROY, "%m, %m, %M", &container->lock_print,
			container->cool_down, container->n_fork,
			container->size) == true)
		return (free(philosopher), true);
	free(philosopher);
	return (false);
}

static bool	ft_thread_start(t_dllist *container, t_thread_args *philosopher,
		t_dllist_node *node)
{
	size_t	i;

	i = 0;
	container->time_start = ft_get_time_ms();
	while (i < container->size)
	{
		philosopher[i] = ft_thread_init(container, philosopher[i], node);
		if (pthread_create(&philosopher[i].thread_id, NULL, ft_routine,
				&philosopher[i]) != 0)
			return (true);
		node = node->next;
		++i;
	}
	return (false);
}

static bool	ft_check_death()
{
	return (false);
}

static bool	ft_thread_join(t_thread_args *philosopher, size_t size)
{
	size_t	i;
	void	*result;

	i = 0;
	while (i < size)
		if (pthread_join(philosopher[i++].thread_id, &result) != 0)
			return (true);
	return (false);
}
