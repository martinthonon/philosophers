/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:20:58 by mathonon          #+#    #+#             */
/*   Updated: 2023/09/27 10:48:57 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_dllist	*container;

	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	if (ft_arg_init(argc, ++argv, &container) == true)
		return (EXIT_FAILURE);
	if (ft_process(container) == true)
	{
		ft_list_destroy(container);
		return (EXIT_FAILURE);
	}
	ft_list_destroy(container);
	return (EXIT_SUCCESS);
}
