#include "philo.h"

bool ft_container_create(t_dllist **struct_sentinel);
bool ft_container_init(int argc, char **argv, t_dllist *struct_sentinel);

bool ft_container_create(t_dllist **struct_sentinel)
{
    *struct_sentinel = ft_list_new();
    if (*struct_sentinel != NULL)
        return(false);
    return (true);
}

bool ft_container_init(int argc, char **argv, t_dllist *struct_sentinel)
{
    bool is_overflow;

    is_overflow = false;
    struct_sentinel->size = ft_str_to_ul(argv[0], &is_overflow);
    struct_sentinel->time_to_die = ft_str_to_ui(argv[1], &is_overflow);
    struct_sentinel->time_to_eat = ft_str_to_ui(argv[2], &is_overflow);
    struct_sentinel->time_to_sleep = ft_str_to_ui(argv[3], &is_overflow);
    if (argc == 6)
    {
        struct_sentinel->n_meals_till_full = malloc(sizeof(uint32_t));
        if (struct_sentinel == NULL)
            return (true);
        *struct_sentinel->n_meals_till_full = ft_str_to_ui(argv[4], &is_overflow);
    }
    return (is_overflow);
}