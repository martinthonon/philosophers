/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:36:58 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/28 15:39:36 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	ft_str_to_ul(char *str, bool *is_overflow);
uint32_t	ft_str_to_ui(char *str, bool *is_overflow);

uint64_t	ft_str_to_ul(char *nptr, bool *is_overflow)
{
	size_t	res;
	size_t	cpy;

	if (*nptr == '0')
		return (*is_overflow = true);
	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		cpy = res;
		res = res * 10 + (uint64_t)(*nptr - '0');
		if (res < cpy)
			return (*is_overflow = true);
		++nptr;
	}
	if (*nptr != '\0')
		return (*is_overflow = true);
	return (res);
}

uint32_t	ft_str_to_ui(char *nptr, bool *is_overflow)
{
	uint32_t	res;
	uint32_t	cpy;

	if (*nptr == '0')
		return (*is_overflow = true);
	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		cpy = res;
		res = res * 10 + (uint32_t)(*nptr - '0');
		if (res < cpy)
			return (*is_overflow = true);
		++nptr;
	}
	if (*nptr != '\0')
		return (*is_overflow = true);
	return (res);
}
