/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:28:15 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 16:50:46 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	drop_fork(t_data *data, t_phi *phi)
{
	int	last;
	// int	first;

	last = (phi->id == data->number_of_philo - 1);
	// first = (data->number_of_philo - 1) * (phi->id == 0);
	pthread_mutex_unlock(&data->forks[(phi->id + 1) * !last]);
	printf("... %d dropped fork : %d\n", phi->id, (phi->id + 1) * !last);
	pthread_mutex_unlock(&data->forks[(phi->id)]);
	printf("... %d dropped fork : %d\n", phi->id, phi->id);
}

void	pick_fork(t_data *data, t_phi *phi)
{
	int	last;
	// int	first;

	last = (phi->id == data->number_of_philo - 1);
	// first = (data->number_of_philo - 1) * (phi->id == 0);
	pthread_mutex_lock(&data->forks[(phi->id + 1) * !last]);
	printf("... %d picked fork : %d\n", phi->id, (phi->id + 1) * !last);
	pthread_mutex_lock(&data->forks[(phi->id)]);
	printf("... %d picked fork : %d\n", phi->id, phi->id);
}

void	*eat_routine(void *arg)
{
	t_data	*data;
	t_phi	*phi;

	phi = (t_phi *) arg;
	data = get_struct();
	pick_fork(data, phi);
	pthread_mutex_lock(&data->wait_display);
	print_timer(data->t0);
	printf("%d is eating\n", phi->id);
	pthread_mutex_unlock(&data->wait_display);
	usleep(data->time_to_eat * 1000);
	drop_fork(data, phi);
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
