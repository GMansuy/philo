/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:59:29 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 16:53:29 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	join_threads(t_data *data)
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

static int	prio_loop(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		if (data->phi[i].state == waiting)
		{
			data->phi[i].state = eating;
			if (pthread_create(&data->phi[i].th, NULL,
					&th_wait, NULL) != 0)
				return (1);			
		}
		else if (data->phi[i].state == eating)
		{
			if (pthread_create(&data->phi[i].th, NULL,
					&eat_routine, (void *)&data->phi[i]) != 0)
				return (1);
		}
		else if (data->phi[i].state == sleeping)
		{
			if (pthread_create(&data->phi[i].th, NULL,
					&sleep_routine, (void *)&data->phi[i]) != 0)
				return (1);
		}
	}	
	return (0);
}

static int	main_loop(t_data *data)
{
	init_mutex(data);
	while (!data->death)
	{
		prio_loop(data);
		if (join_threads(data) != 0)
			return (3);
	}
	destroy_mutex(data);
	return (0);
}

int	generate_philo(t_data *data)
{
	int	signal;

	if (allocate_phi(data) != 0)
		return (1);
	if (allocate_forks(data) != 0)
		return (2);
	signal = main_loop(data);
	printf("\nsignal -- %d\n", signal);
	return (0);
}
