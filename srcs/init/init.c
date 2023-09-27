/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:41:17 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/27 18:17:48 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_arg_init(int argc, char **argv, t_dllist **container);

bool	ft_arg_init(int argc, char **argv, t_dllist **container)
{
	if (ft_container_create(container) == true)
		return (true);
	if (ft_container_init(argc, argv, *container) == true
		|| ft_list_init((*container)->sentinel_node,
			(*container)->size) == true)
	{
		ft_list_destroy(*container);
		return (true);
	}
	return (false);
}
