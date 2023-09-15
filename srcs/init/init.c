/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:41:17 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/15 10:43:26 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_arg_init(int argc, char **argv, t_dllist **struct_sentinel);

bool	ft_arg_init(int argc, char **argv, t_dllist **struct_sentinel)
{
	if (ft_container_create(struct_sentinel) == true)
		return (true);
	if (ft_container_init(argc, argv, *struct_sentinel) == true
		|| ft_list_init((*struct_sentinel)->sentinel_node,
			(*struct_sentinel)->size) == true)
	{
		ft_list_destroy(*struct_sentinel);
		return (true);
	}
	return (false);
}
