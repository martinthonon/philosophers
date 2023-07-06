#include "philo.h"

bool ft_list_init(t_dllist_node *sentinel_node, size_t list_size);

bool ft_list_init(t_dllist_node *sentinel_node, size_t list_size)
{
    size_t i;

    i = 0;
    while (i < list_size)
        if (ft_list_add_back(sentinel_node, i++) == NULL)
            return (true);
    return (false);
}