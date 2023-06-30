#include "philo.h"

bool ft_philo_init(int argc, char **argv, t_dllist *struct_sentinel);

bool ft_philo_init(int argc, char **argv, t_dllist *struct_sentinel)
{
    bool is_overflow;

    is_overflow = false;
    struct_sentinel->size = ft_str_to_ul(argv[0], &is_overflow);
    struct_sentinel->time_to_die = ft_str_to_ui(argv[1], &is_overflow);
    struct_sentinel->time_to_eat = ft_str_to_ui(argv[2], &is_overflow);
    struct_sentinel->time_to_sleep = ft_str_to_ui(argv[3], &is_overflow);
    if (argc == 6)
        struct_sentinel->n_meals_till_full = ft_str_to_ui(argv[4], &is_overflow);
    return (is_overflow);
}
