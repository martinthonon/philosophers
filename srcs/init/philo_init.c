#include "philo.h"

bool ft_philo_init(int argc, char **argv, t_dllist **struct_sentinel);


bool ft_philo_init(int argc, char **argv, t_dllist **struct_sentinel)
{

    if (ft_container_create(struct_sentinel) == true)
        return (true);
    if (ft_container_init(argc, argv, *struct_sentinel) == true || ft_list_init((*struct_sentinel)->sentinel_node, (*struct_sentinel)->size) == true)
    {
        ft_list_destroy(*struct_sentinel);
        return (true);
    }
    return (false);
}
