/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:06:59 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/05 15:43:09 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	join_phi(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		if (pthread_join(data->phi[i].th, NULL) != 0)
			return (1);
		if (pthread_join(data->phi[i].time_th, NULL) != 0)
			return (1);
	}
	return (0);
}

void	*routine(void *phi_arg)
{
	t_phi	*phi;

	phi = (t_phi *)phi_arg;
	while (1)
	{
		if (go_eat(phi) != 0)
			return (NULL);
		if (go_sleep(phi) != 0)
			return (NULL);
		if (go_think(phi) != 0)
			return (NULL);
		pthread_mutex_lock(phi->wait.wait_stop);
		if (phi->wait.stop)
			return (pthread_mutex_unlock(phi->wait.wait_stop), NULL);
		pthread_mutex_unlock(phi->wait.wait_stop);
	}
	return (NULL);
}

int	impair_th_loop(t_data *data)
{
	int	i;
	
	i = -1;
	magic_usleep(data->time_to_eat, data->t0, &data->phi[0].wait);
	while (++i < data->number_of_philo)
	{
		if (data->phi[i].group == impair && pthread_create(&data->phi[i].th, NULL,
			&routine, &data->phi[i]) != 0)
			return (1);
	}
	return (0);
}

int	pair_th_loop(t_data *data)
{
	int	i;
	
	i = -1;
	while (++i < data->number_of_philo)
	{
		if (data->phi[i].group == pair && pthread_create(&data->phi[i].th, NULL,
			&routine, &data->phi[i]) != 0)
			return (1);
	}
	return (0);
}

int	philo_loop(t_data *data)
{
	int	i;
	
	i = -1;
	if (init_mutex(data) != 0)
		return (1);
	init_timer(&data->t0);
	pair_th_loop(data);
	impair_th_loop(data);
	monitoring_loop(data);
	if (join_phi(data) != 0)
		return (1);
	return (0);
}
