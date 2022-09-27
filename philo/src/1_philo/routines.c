/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:28:15 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 18:48:37 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	go_to_bed(t_data *data, t_phi *phi)
{
	pthread_mutex_lock(&data->wait_sleep);
	get_timer(data->t0);
	printf("%d is sleeping\n", phi->id);
	pthread_mutex_unlock(&data->wait_sleep);
	phi->state = sleeping;
	usleep(data->time_to_sleep);
}


void	eat(t_data *data, t_phi *phi)
{
	pthread_mutex_lock(&data->wait_eat);
	get_timer(data->t0);
	printf("%d is eating\n", phi->id);
	data->start_pair++;
	pthread_mutex_unlock(&data->wait_eat);
	phi->state = eating;
	usleep(data->time_to_eat);
}

void	*routine(void *arg)
{
	t_data	*data;
	t_phi	*phi;
	phi = (t_phi *) arg;

	data = get_struct();
	pthread_mutex_lock(&data->forks[phi->id]);
	printf("%d grabs the fork %d...\n", phi->id, phi->id);
	if (phi->id == data->number_of_philo - 1)
	{
		pthread_mutex_lock(&data->forks[0]);
		printf("%d grabs the fork %d...\n", phi->id, 0);		
	}
	else
	{
		pthread_mutex_lock(&data->forks[phi->id + 1]);
		printf("%d grabs the fork %d...\n", phi->id, phi->id + 1);
	}
	eat(data, phi);
	pthread_mutex_unlock(&data->forks[phi->id]);
	printf("%d pose the fork %d...\n", phi->id, phi->id);
	if (phi->id == data->number_of_philo - 1)
	{
		pthread_mutex_unlock(&data->forks[0]);
		printf("%d pose the fork %d...\n", phi->id, 0);				
	}
	else
	{
		pthread_mutex_unlock(&data->forks[phi->id + 1]);
		printf("%d pose the fork %d...\n", phi->id, phi->id + 1);		
	}
	go_to_bed(data, phi);
	return (NULL);
}
