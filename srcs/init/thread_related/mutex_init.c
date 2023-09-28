/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:49:53 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/28 09:41:00 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool		ft_mutex_flag(uint8_t flag, char *formats, ...);
static bool	ft_mutex(uint8_t flag, pthread_mutex_t *mutex);
static bool	ft_mutex_ptr(uint8_t flag, pthread_mutex_t *mutex, ssize_t size);

bool	ft_mutex_flag(uint8_t flag, char *formats, ...)
{
	va_list	ap;

	va_start(ap, formats);
	while (*formats != '\0')
	{
		if (*formats++ == '%')
		{
			if (*formats == 'm')
			{
				if (ft_mutex(flag, va_arg(ap, pthread_mutex_t *)) == true)
					return (va_end(ap), true);
			}
			else if (*formats == 'M')
				if (ft_mutex_ptr(flag, va_arg(ap, pthread_mutex_t *),
						va_arg(ap, ssize_t)) == true)
					return (va_end(ap), true); 
		}
	}
	va_end(ap);
	return (false);
}

bool	ft_mutex(uint8_t flag, pthread_mutex_t *mutex)
{
	if (flag == FLAG_INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != INIT)
			return (true);
	}
	else
		if (pthread_mutex_destroy(mutex) != DESTROY)
			return (true);
	return (false);
}

bool	ft_mutex_ptr(uint8_t flag, pthread_mutex_t *mutex, ssize_t size)
{
	ssize_t	i;

	i = -1;
	if (flag == FLAG_INIT)
	{
		while (++i < size)
		{
			if (pthread_mutex_init(&mutex[i], NULL) != INIT)
			{
				size = -1;
				while (++size < i)
					pthread_mutex_destroy(&mutex[size]);
				return (true);
			}
		}
	}
	else
		while (++i < size)
			if (pthread_mutex_destroy(&mutex[i]) != DESTROY)
				return (true);
	return (false);
}
