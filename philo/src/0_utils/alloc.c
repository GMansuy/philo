/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:16:42 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 17:09:14 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	allocate_phi(t_data *data)
{
	data->phi = malloc(sizeof(t_phi) * data->number_of_philo + 1);
	if (!data->phi)
		return (msg("malloc : Error\n"), 1);
	init_phi(data);
	return (0);
}

int	allocate_forks(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo + 1);
	if (!data->forks)
		return (msg("malloc : Error\n"), 1);
	return (0);
}

int	alloc_data(t_data *data)
{
	if (allocate_phi(data) != 0)
		return (1);
	if (allocate_forks(data) != 0)
		return (2);
	return (0);
}
