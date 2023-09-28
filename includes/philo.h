/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:12:16 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/28 15:50:18 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include <sys/time.h>

# define NO_MEAL 0
# define FLAG_INIT 1
# define FLAG_DESTROY 0
# define INIT 0
# define DESTROY 0
# define CREATED 0
# define JOINED 0
# define FORK "has taken fork"
# define EATING "is eating"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define DEAD "died"

typedef enum node_type
{
	NODE,
	SENTINEL_NODE
}			t_node_type;

typedef struct s_dllist_node 
{
	struct s_dllist_node	*prev;
	struct s_dllist_node	*next;
	t_node_type				node_type;
	ssize_t					index;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	uint32_t				n_meal;
	_Atomic uint64_t		time_since_last_meal;

}				t_dllist_node;

typedef struct s_dllist
{
	t_dllist_node		*sentinel_node; 
	pthread_mutex_t		*n_fork;
	pthread_mutex_t		lock_print;
	ssize_t				size;
	uint64_t			time_start;
	uint32_t			time_to_die;
	uint32_t			time_to_eat;
	uint32_t			time_to_sleep;
	uint32_t			n_meal_till_full;
	uint32_t			meal_count;
	_Atomic bool		is_plenty;
	_Atomic bool		is_dead;
}				t_dllist;

typedef struct s_thread_args
{
	pthread_t		thread_id;
	t_dllist		*container;
	t_dllist_node	*node;
}				t_thread_args;

t_thread_args	*ft_thread_init(t_dllist *container, t_thread_args *philosopher,
					t_dllist_node *node);
bool			ft_container_create(t_dllist **struct_sentinel);
bool			ft_container_init(int argc, char **argv,
					t_dllist *struct_sentinel);
bool			ft_list_init(t_dllist_node *sentinel_node, ssize_t list_size);
bool			ft_arg_init(int argc, char **argv, t_dllist **struct_sentinel);
bool			ft_thread_create(ssize_t size, t_thread_args **philosopher);
bool			ft_mutex_flag(uint8_t flag, char *formats, ...);

t_dllist_node	*ft_list_add_back(t_dllist_node *sentinel_node, ssize_t index);
t_dllist		*ft_list_new(void);
void			ft_list_destroy(t_dllist *struct_sentinel);

bool			ft_process(t_dllist *container);
void			*ft_routine(void *arg);
bool			ft_sub_routine(t_dllist *container, t_thread_args *philosopher);

uint64_t		ft_str_to_ul(char *str, bool *is_overflow);
uint64_t		ft_get_time_ms(void);
uint32_t		ft_str_to_ui(char *str, bool *is_overflow);
bool			ft_diff_time_ms(uint64_t start_time,
					uint64_t diff_time);
void			ft_usleep(uint64_t ms);
void			ft_free(const char *formats, ...);
bool			ft_set_mutex(uint8_t flag, t_dllist *container);
void			ft_atomic_print(t_thread_args *philosopher, char *status);

#endif
