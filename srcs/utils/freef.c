/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freef.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:34:16 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/28 15:35:25 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(const char *formats, ...);

void	ft_free(const char *formats, ...)
{
	va_list	ap;
	int		i;
	void	**dptr;

	va_start(ap, formats);
	while (*formats != '\0')
	{
		if (*formats == '%')
		{
			++formats;
			if (*formats == 'p')
				free(va_arg(ap, void *));
			else if (*formats == 'P')
			{
				dptr = va_arg(ap, void **);
				i = 0;
				while (dptr != NULL && dptr[i] != NULL)
					free(dptr[i++]);
				free(dptr);
			}
		}
		++formats;
	}
	va_end(ap);
}
