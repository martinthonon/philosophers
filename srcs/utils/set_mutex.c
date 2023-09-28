/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:35:38 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/28 15:36:43 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_set_mutex(uint8_t flag, t_dllist *container);

bool	ft_set_mutex(uint8_t flag, t_dllist *container)
{
	return (ft_mutex_flag(flag, "%m, %M", &container->lock_print, \
			container->n_fork, container->size));
}
