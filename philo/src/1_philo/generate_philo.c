/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:59:29 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 18:28:07 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int join_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		if (pthread_join(data->phi[i].th, NULL) != 0)
			return (1);
	}
	return (0);
}

static int	prio_loop(t_data *data, t_phi *phi, int prio)
{
	int	i;
	
	i = -1;
	while (++i < data->number_of_philo)
	{
		if (prio == phi[i].group)
		{
			if (pthread_create(&phi[i].th, NULL, &routine,
				 (void *)&phi[i]) != 0)
				 return (1);
		}
	}	
	return (0);
}

static int	main_loop(t_data *data, t_phi *phi)
{
	int	waiting;
	
	waiting = 0;
	init_mutex(data);
	while (!data->death)
	{
		if (prio_loop(data, phi, impair) != 0)
			return (1);
		while (data->start_pair != 3)
			waiting++;
		printf("\n");
		waiting = 0;
		data->start_pair = 0;
		if (prio_loop(data, phi, pair) != 0)
			return (2);
		while (data->start_pair != 3)
			waiting++;
		printf("\n");
		waiting = 0;
		data->start_pair = 0;
		if (join_threads(data) != 0)
			return (3);
	}
	destroy_mutex(data);
	return (0);
}

int	generate_philo(t_data *data)
{
	if (allocate_phi(data) != 0)
		return (1);
	if (allocate_forks(data) != 0)
		return (2);
	main_loop(data, data->phi);
	return (0);
}
