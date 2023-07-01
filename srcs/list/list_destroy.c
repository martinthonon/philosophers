#include "philo.h"

void ft_list_destroy(t_dllist *struct_sentinel);

void ft_list_destroy(t_dllist *struct_sentinel)
{
    t_dllist_node *sentinel_node_cpy;
    t_dllist_node *node_tmp;

    sentinel_node_cpy = struct_sentinel->sentinel_node;
    sentinel_node_cpy = sentinel_node_cpy->next;
    while (sentinel_node_cpy != struct_sentinel->sentinel_node)
    {
        node_tmp = sentinel_node_cpy;
        sentinel_node_cpy = sentinel_node_cpy->next;
        free(node_tmp);
    }
    free(sentinel_node_cpy);
    free(struct_sentinel->n_meals_till_full);
    free(struct_sentinel);
}
