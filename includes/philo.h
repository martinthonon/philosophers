#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

typedef struct s_dllist_node {

    struct s_dllist_node *prev;
    struct s_dllist_node *next;
    size_t index;
    uint32_t n_meals;
    uint8_t status;
}              t_dllist_node;

typedef struct s_dllist
{
    t_dllist_node *sentinel_node;
    pthread_mutex_t *n_forks;
    size_t size;
    uint32_t time_to_die;
    uint32_t time_to_eat;
    uint32_t time_to_sleep;
    uint32_t n_meals_till_full;
    
}              t_dllist;

enum e_status {

    thinking = 0,
    eating = 1,
    sleeping = 2,
};


bool ft_container_init(t_dllist **struct_sentinel);
bool ft_philo_init(int argc, char **argv, t_dllist *struct_sentinel);

t_dllist_node *ft_list_add_back(t_dllist_node *sentinel_node, size_t index);
void ft_list_destroy(t_dllist *struct_sentinel);
t_dllist *ft_list_new();

size_t ft_str_to_ul(char *str, bool *is_overflow);
uint32_t ft_str_to_ui(char *str, bool *is_overflow);


#endif