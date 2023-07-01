#include "philo.h"

t_dllist *ft_list_new();

t_dllist *ft_list_new()
{
    t_dllist *struct_sentinel;
    t_dllist_node *sentinel_node;

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
    struct_sentinel->n_meals_till_full = NULL;
    sentinel_node->prev = sentinel_node;
    sentinel_node->next = sentinel_node;
    return (struct_sentinel);
}
