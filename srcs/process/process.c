/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:46:33 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/15 17:13:47 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_process(t_dllist *container);

bool	ft_process(t_dllist *container)
{
	t_thread_args	*philosopher;

	philosopher = NULL;
	if (ft_thread_create(container->size, philosopher) == true)
		return (true);
	if (ft_set_mutex(INIT, container) == true)
		return (free(philosopher), true);
	if (ft_sub_routine(container, philosopher) == true) //set a bool ?
	{
		ft_set_mutex(DESTROY, container);
		return (free(philosopher), true);
	}
	if (ft_set_mutex(DESTROY, container) == true)
		return (free(philosopher), true);	
	return (free(philosopher), false);
}