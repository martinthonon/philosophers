#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <stdarg.h>
#include <sys/time.h>

# ifdef __linux__
#  define SIZEOF_PTHREAD_MUTEX_T 40
# elif __MACH__
#  define SIZEOF_PTHREAD_MUTEX_T 56
# endif

# define INIT 1
# define DESTROY 0


typedef struct s_dllist_node 
{
    struct s_dllist_node *prev;
    struct s_dllist_node *next;
    size_t index;
    uint64_t time_till_last_meal;
    uint32_t n_meal;
    uint8_t status;
}              t_dllist_node;

typedef struct s_dllist
{
    t_dllist_node *sentinel_node;
    pthread_mutex_t *n_fork;
    pthread_mutex_t lock_print;
    size_t size;
    uint32_t time_to_die;
    uint32_t time_to_eat;
    uint32_t time_to_sleep;
    uint32_t *n_meal_till_full;
    
}              t_dllist;

typedef struct s_thread_args
{
    pthread_t thread_id;
    t_dllist *container;
    t_dllist_node *node;
}               t_thread_args;

enum e_status {

    thinking = 0,
    hungry = 1,
    eating = 2,
    sleeping = 3,
    dead = 4
};


t_thread_args ft_thread_init(t_dllist *container, t_thread_args philosopher, t_dllist_node *node);
bool ft_container_create(t_dllist **struct_sentinel);
bool ft_container_init(int argc, char **argv, t_dllist *struct_sentinel);
bool ft_list_init(t_dllist_node *sentinel_node, size_t list_size);
bool ft_arg_init(int argc, char **argv, t_dllist **struct_sentinel);
bool ft_thread_create(size_t size, t_thread_args **philosopher);
bool ft_mutex_flag(uint8_t flag, char *formats, ...);
// bool ft_mutex_init(size_t size, pthread_mutex_t *fork);
// bool ft_mutex_destroy(size_t size, pthread_mutex_t *fork);

t_dllist_node *ft_list_add_back(t_dllist_node *sentinel_node, size_t index);
t_dllist *ft_list_new(void);
void ft_list_destroy(t_dllist *struct_sentinel);

void *ft_routine(void *arg);
bool ft_take_fork(t_thread_args *philosopher);
bool ft_put_fork(t_thread_args *philosopher);
bool ft_process(t_dllist *container);

void ft_think(t_thread_args *philosopher);
void ft_eat(t_thread_args *philosopher);
void ft_sleep(t_thread_args *philosopher);

uint64_t ft_str_to_ul(char *str, bool *is_overflow);
uint64_t ft_get_time_ms(void);
uint32_t ft_str_to_ui(char *str, bool *is_overflow);
bool ft_diff_time_ms(uint64_t start_time, uint64_t diff_time);
void	ft_free(const char *formats, ...);

#endif