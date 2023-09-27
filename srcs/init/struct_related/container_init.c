/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:44:20 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/27 16:30:41 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_container_create(t_dllist **container);
bool	ft_container_init(int argc, char **argv, t_dllist *container);

bool	ft_container_create(t_dllist **container)
{
	*container = ft_list_new();
	if (*container != NULL)
		return (false);
	return (true);
}

bool	ft_container_init(int argc, char **argv, t_dllist *container)
{
	bool	is_overflow;

	is_overflow = false;
	container->is_dead = false;
	container->size = (ssize_t)ft_str_to_ul(argv[0], &is_overflow);
	container->time_to_die = ft_str_to_ui(argv[1], &is_overflow);
	container->time_to_eat = ft_str_to_ui(argv[2], &is_overflow);
	container->time_to_sleep = ft_str_to_ui(argv[3], &is_overflow);
	container->n_fork = malloc(sizeof(pthread_mutex_t) * (size_t)(container->size));
	if (container->n_fork == NULL)
		return (true);
	if (argc == 6)
		container->n_meal_till_full = ft_str_to_ui(argv[4], &is_overflow);
	else
		container->n_meal_till_full = NO_MEAL;
	return (is_overflow);
}
