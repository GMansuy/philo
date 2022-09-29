/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:27:13 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 16:53:05 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
	}
	if (pthread_mutex_init(&data->wait_monitoring, NULL) != 0)
		return (2);
	return (0);
}

void	init_phi(t_data *data)
{
	int	i;
	int	last;

	i = 0;
	while (i < data->number_of_philo)
	{
		last = !(i == data->number_of_philo - 1);
		data->phi[i].id = i;
		if (i % 2 == 0)
		{
			data->phi[i].group = pair;
			data->phi[i].state = thinking;
		}
		else
		{
			data->phi[i].group = impair;
			data->phi[i].state = eating;
		}
		data->phi[i].left_fork = &data->forks[i];
		data->phi[i].right_fork = &data->forks[(i + 1) * last];
		data->phi[i].t0 = &data->t0;
		data->phi[i].wait_monitoring = &data->wait_monitoring;
		data->phi[i].time_to_eat = data->time_to_eat * 1000;
		data->phi[i].time_to_sleep = data->time_to_sleep * 1000;
		i++;
	}
}

void	init_all(t_data *data)
{
	data->number_of_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->number_of_eat = 0;
	data->death = 0;
	data->prio = pair;
	data->forks = NULL;
	data->phi = NULL;
}
