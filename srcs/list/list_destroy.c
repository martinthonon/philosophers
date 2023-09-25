/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:34:35 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/25 13:50:48 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_list_destroy(t_dllist *struct_sentinel);

void	ft_list_destroy(t_dllist *struct_sentinel)
{
	t_dllist_node	*node;
	t_dllist_node	*node_tmp;

	node = struct_sentinel->sentinel_node->next;
	while (node->node_type != SENTINEL_NODE)
	{
		node_tmp = node;
		node = node->next;
		free(node_tmp);
	}
	free(node);
	free(struct_sentinel->n_fork);
	free(struct_sentinel);
}
