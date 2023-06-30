#include "philo.h"

int main(int argc, char **argv)
{
    t_dllist *container;

    if (argc < 5 || argc > 6 || ft_container_init(&container) == true)
        return (1);
    if (ft_philo_init(argc, ++argv, container) == true) 
    {
        printf("init error\n");
        ft_list_destroy(container);
        return (1); 
    }
    printf("%lu\n", container->size);
    printf("%u\n", container->time_to_die);
    printf("%u\n", container->time_to_eat);
    printf("%u\n", container->time_to_sleep);
    printf("%u\n", container->n_meals_till_full);
    ft_list_destroy(container);
    return (0);
}