/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:01:52 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/27 16:27:16 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_dllist_node	*ft_list_add_back(t_dllist_node *sentinel_node, ssize_t index);

t_dllist_node	*ft_list_add_back(t_dllist_node *sentinel_node, ssize_t index)
{
	t_dllist_node	*new_node;
	t_dllist_node	*prev_node;

	prev_node = sentinel_node->prev;
	new_node = malloc(sizeof(t_dllist_node));
	if (new_node == NULL)
		return (NULL);
	new_node->prev = prev_node;
	new_node->next = sentinel_node;
	new_node->node_type = NODE;
	new_node->index = index;
	sentinel_node->prev = new_node;
	prev_node->next = new_node;
	return (new_node);
}
