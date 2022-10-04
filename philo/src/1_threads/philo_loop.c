/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:06:59 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/04 18:42:54 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *phi_arg)
{
	t_phi	*phi;

	phi = (t_phi *)phi_arg;
	if (pthread_create(&phi->time_th, NULL, &death_timer, phi) != 0)
			return (NULL);
	if (phi->group == impair)
		usleep(phi->args.time_to_eat);
	while (1)
	{
		if (go_eat(phi) != 0)
			return (NULL);
		if (go_sleep(phi) != 0)
			return (NULL);
		if (go_think(phi) != 0)
			return (NULL);
		pthread_mutex_lock(phi->wait.wait_stop);
		if (phi->stop)
			return (pthread_mutex_unlock(phi->wait.wait_stop), NULL);
		pthread_mutex_unlock(phi->wait.wait_stop);
	}
	return (NULL);
}

int	philo_loop(t_data *data)
{
	int	i;
	int	j;
	int group;

	j = 2;
	if (init_mutex(data) != 0)
		return (1);
	group = pair;
	init_timer(&data->t0);
	while (j > 0)
	{
		i = -1;
		while (++i < data->number_of_philo)
		{
			if (data->phi[i].group == group && pthread_create(&data->phi[i].th, NULL,
				&routine, &data->phi[i]) != 0)
				return (2);
		}
		j--;
		group = impair;
	}
	monitoring_loop(data);
	return (0);
}
