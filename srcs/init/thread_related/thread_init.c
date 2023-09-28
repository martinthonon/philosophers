/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:58:36 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/28 15:47:45 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool			ft_thread_create(ssize_t size, t_thread_args **philosopher);
t_thread_args	*ft_thread_init(t_dllist *container, t_thread_args *philosopher,
					t_dllist_node *node);

bool	ft_thread_create(ssize_t size, t_thread_args **philosopher)
{
	*philosopher = malloc(sizeof(t_thread_args) * (size_t)size);
	return (*philosopher == NULL);
}

t_thread_args	*ft_thread_init(t_dllist *container, t_thread_args *philosopher,
		t_dllist_node *node)
{
	node->left_fork = &container->n_fork[node->index];
	if (node->index == 0)
		node->right_fork = &container->n_fork[container->size - 1];
	else
		node->right_fork = &container->n_fork[(node->index - 1)
			% container->size];
	node->time_since_last_meal = container->time_start;
	node->n_meal = NO_MEAL;
	philosopher->container = container;
	philosopher->node = node;
	return (philosopher);
}
