/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:49:53 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/15 10:58:22 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool		ft_mutex_flag(uint8_t flag, char *formats, ...);
static bool	ft_mutex(uint8_t flag, pthread_mutex_t *mutex);
static bool	ft_mutex_ptr(uint8_t flag, pthread_mutex_t *mutex, size_t size);

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
						va_arg(ap, size_t)) == true)
					return (va_end(ap), true); 
		}
	}
	va_end(ap);
	return (false);
}

bool	ft_mutex(uint8_t flag, pthread_mutex_t *mutex)
{
	if (flag == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			return (true);
	}
	else
		if (pthread_mutex_destroy(mutex) != 0)
			return (true);
	return (false);
}

bool	ft_mutex_ptr(uint8_t flag, pthread_mutex_t *mutex, size_t size)
{
	size_t	i;

	i = 0;
	if (flag == INIT)
	{
		while (i < size)
		{
			if (pthread_mutex_init(&mutex[i], NULL) != 0)
			{
				size = 0;
				while (size < i)
					pthread_mutex_destroy(&mutex[size++]);
				return (true);
			}
			++i;
		}
	}
	else
		while (i < size)
			if (pthread_mutex_destroy(&mutex[i++]) != 0)
				return (true);
	return (false);
}
