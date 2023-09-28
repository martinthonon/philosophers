/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:46:33 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/28 15:27:49 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_process(t_dllist *container);

bool	ft_process(t_dllist *container)
{
	t_thread_args	*philosopher;
	bool			sub_routine;
	bool			mutex_destroy;

	if (ft_thread_create(container->size, &philosopher) == true)
		return (true);
	if (ft_set_mutex(FLAG_INIT, container) == true)
		return (free(philosopher), true);
	sub_routine = ft_sub_routine(container, philosopher);
	mutex_destroy = ft_set_mutex(FLAG_DESTROY, container);
	return (free(philosopher), sub_routine || mutex_destroy);
}
