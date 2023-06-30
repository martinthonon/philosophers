#include "philo.h"

t_dllist_node *ft_list_add_back(t_dllist_node *sentinel_node, size_t index);

t_dllist_node *ft_list_add_back(t_dllist_node *sentinel_node, size_t index)
{
    t_dllist_node *new_node;
    t_dllist_node *prev_node;

    prev_node = sentinel_node->prev;
    new_node = malloc(sizeof(t_dllist_node));
    if (new_node == NULL)
        return (NULL);
    new_node->index = index;
    new_node->prev = prev_node;
    new_node->next = sentinel_node;
    sentinel_node->prev = new_node;
    prev_node->next = new_node;
    return (new_node);
}
