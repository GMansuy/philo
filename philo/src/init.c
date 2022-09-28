/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:27:13 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 16:05:52 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
	}
	if (pthread_mutex_init(&data->wait_eat, NULL) != 0)
		return (2);
	if (pthread_mutex_init(&data->wait_sleep, NULL) != 0)
		return (3);
	if (pthread_mutex_init(&data->wait_think, NULL) != 0)
		return (4);
	if (pthread_mutex_init(&data->wait_display, NULL) != 0)
		return (5);
	return (0);
}

void	init_phi(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->phi[i].id = i;
		if (i % 2 == 0)
		{
			data->phi[i].group = pair;
			data->phi[i].state = sleeping;
		}
		else
		{
			data->phi[i].group = impair;
			data->phi[i].state = eating;
		}
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
