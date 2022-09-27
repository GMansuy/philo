/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:49:16 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 16:46:23 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_data	*get_struct(void)
{
	static t_data	data;

	return (&data);
}

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
