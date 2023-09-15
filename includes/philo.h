/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:12:16 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/15 12:33:44 by mathonon         ###   ########.fr       */
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
# define INIT 1
# define DESTROY 0
# define FORK "has taken fork"
# define EATING "is eating"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define DEAD "died"

typedef struct s_dllist_node 
{
	struct s_dllist_node	*prev;
	struct s_dllist_node	*next;
	size_t					index;
	uint64_t				time_till_last_meal;
	uint32_t				slow_death;

}				t_dllist_node;

typedef struct s_dllist
{
	t_dllist_node	*sentinel_node;
	pthread_mutex_t	*n_fork;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	cool_down;
	size_t			size;
	uint64_t		time_start;
	uint32_t		time_to_die;
	uint32_t		time_to_eat;
	uint32_t		time_to_sleep;
	uint32_t		n_meal_till_full;
	_Atomic bool	is_dead;
}				t_dllist;

typedef struct s_thread_args
{
	pthread_t		thread_id;
	t_dllist		*container;
	t_dllist_node	*node;
}				t_thread_args;

t_thread_args	ft_thread_init(t_dllist *container, t_thread_args philosopher,
					t_dllist_node *node);
bool			ft_container_create(t_dllist **struct_sentinel);
bool			ft_container_init(int argc, char **argv,
					t_dllist *struct_sentinel);
bool			ft_list_init(t_dllist_node *sentinel_node, size_t list_size);
bool			ft_arg_init(int argc, char **argv, t_dllist **struct_sentinel);
bool			ft_thread_create(size_t size, t_thread_args *philosopher);
bool			ft_mutex_flag(uint8_t flag, char *formats, ...);

t_dllist_node	*ft_list_add_back(t_dllist_node *sentinel_node, size_t index);
t_dllist		*ft_list_new(void);
void			ft_list_destroy(t_dllist *struct_sentinel);

void			*ft_routine(void *arg);
bool			ft_process(t_dllist *container);

uint64_t		ft_str_to_ul(char *str, bool *is_overflow);
uint64_t		ft_get_time_ms(void);
uint32_t		ft_str_to_ui(char *str, bool *is_overflow);
bool			ft_diff_time_ms(uint64_t start_time,
					uint64_t diff_time); //is use ?
bool			ft_timeout(t_thread_args *philosopher, uint64_t time_till);
uint64_t		ft_time_left_to_die(t_thread_args *philosopher);
void			ft_usleep(uint64_t ms);
void			ft_free(const char *formats, ...);
void			ft_atomic_print(t_thread_args *philosopher, char *status);

#endif
