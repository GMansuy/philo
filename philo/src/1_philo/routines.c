/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:28:15 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 18:26:52 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	eat(t_data *data, t_phi *phi)
{
	pthread_mutex_lock(&data->wait_eat);
	get_timer(data->t0);
	printf("%d is eating\n", phi->id);
	data->start_pair++;
	pthread_mutex_unlock(&data->wait_eat);
	usleep(data->time_to_eat);
}

void	*routine(void *arg)
{
	t_data	*data;
	t_phi	*phi;
	phi = (t_phi *) arg;

	data = get_struct();
	pthread_mutex_lock(&data->forks[phi->id]);
	if (phi->id == data->number_of_philo - 1)
		pthread_mutex_lock(&data->forks[0]);
	else
		pthread_mutex_lock(&data->forks[phi->id + 1]);
	eat(data, phi);
	pthread_mutex_unlock(&data->forks[phi->id]);
	if (phi->id == data->number_of_philo - 1)
		pthread_mutex_unlock(&data->forks[0]);
	else
		pthread_mutex_unlock(&data->forks[phi->id + 1]);
	return (NULL);
}
