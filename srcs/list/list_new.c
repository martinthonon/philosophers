/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:36:18 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/25 11:42:01 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_dllist	*ft_list_new(void);

t_dllist	*ft_list_new(void)
{
	t_dllist		*struct_sentinel;
	t_dllist_node	*sentinel_node;

	struct_sentinel = malloc(sizeof(t_dllist));
	if (struct_sentinel == NULL)
		return (NULL);
	sentinel_node = malloc(sizeof(t_dllist_node));
	if (sentinel_node == NULL)
	{
		free(struct_sentinel);
		return (NULL);
	}
	struct_sentinel->sentinel_node = sentinel_node;
	sentinel_node->prev = sentinel_node;
	sentinel_node->next = sentinel_node;
	sentinel_node->node_type = SENTINEL_NODE;
	return (struct_sentinel);
}
