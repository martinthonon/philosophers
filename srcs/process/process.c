#include "philo.h"

bool ft_process(t_dllist *container);

bool ft_process(t_dllist *container)
{
    t_thread_infos *philosopher;
    t_dllist_node *node;
    size_t i;

    if (ft_thread_init(container, &philosopher) == true)
        return (true);
    node = container->sentinel_node->next;
    i = 0;
    while (i < container->size)
    {
        printf ("Heyy\n");
        philosopher[i].container = container;
        philosopher[i].node = node;
        printf("sentinel node : %p node addr : %p\n",container->sentinel_node, node);
        if (pthread_create(&philosopher[i].thread_id, NULL, ft_routine, &philosopher[i]) != 0)
            return (true);
        node = node->next;
        ++i;
    }
     i = 0;
     while (i < container->size) {
        pthread_join(philosopher[i].thread_id, NULL);
        ++i;
     }
         
    return (false);
}