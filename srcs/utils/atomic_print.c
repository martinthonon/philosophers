/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atomic_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:32:34 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/28 15:34:07 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_atomic_print(t_thread_args *philosopher, char *status);

void	ft_atomic_print(t_thread_args *philosopher, char *status)
{
	pthread_mutex_lock(&philosopher->container->lock_print);
	if (philosopher->container->is_dead == false)
		printf("%llu %zu %s\n", ft_get_time_ms()
			- philosopher->container->time_start, philosopher->node->index
			+ 1, status);
	pthread_mutex_unlock(&philosopher->container->lock_print);
}
