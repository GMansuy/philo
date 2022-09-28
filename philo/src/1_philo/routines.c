/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:28:15 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 16:07:09 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// void	go_to_bed(t_data *data, t_phi *phi)
// {
// 	pthread_mutex_lock(&data->wait_sleep);
// 	get_timer(data->t0);
// 	printf("%d is sleeping\n", phi->id);
// 	pthread_mutex_unlock(&data->wait_sleep);
// 	phi->state = sleeping;
// 	usleep(data->time_to_sleep);
// }

void	*eat_routine(void *arg)
{
	t_data	*data;
	t_phi	*phi;

	phi = (t_phi *) arg;
	data = get_struct();
	pthread_mutex_lock(&data->wait_display);
	print_timer(data->t0);
	printf("%d is eating\n", phi->id);
	pthread_mutex_unlock(&data->wait_display);
	usleep(data->time_to_eat * 1000);
	phi->state = sleeping;
	return (NULL);
}

void	*sleep_routine(void *arg)
{
	t_data	*data;
	t_phi	*phi;

	phi = (t_phi *) arg;
	data = get_struct();
	pthread_mutex_lock(&data->wait_display);
	print_timer(data->t0);
	printf("%d is sleeping\n", phi->id);
	pthread_mutex_unlock(&data->wait_display);
	usleep(data->time_to_sleep * 1000);
	phi->state = thinking;
	think_routine(data, phi);
	return (NULL);
}

void	*think_routine(t_data *data, t_phi *phi)
{
	int		time_to_think;

	time_to_think = data->time_to_eat - data->time_to_sleep;
	if (time_to_think <= 0)
		return (phi->state = eating, NULL);
	pthread_mutex_lock(&data->wait_display);
	print_timer(data->t0);
	printf("%d is thinking\n", phi->id);
	pthread_mutex_unlock(&data->wait_display);
	usleep(time_to_think * 1000);
	phi->state = eating;
	return (NULL);
}
