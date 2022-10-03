/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:53:04 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/03 17:44:21 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
int		death_condition(t_phi *phi, time_t timestamp_eat, time_t hunger)
{
		if (phi->stop)
			return (pthread_mutex_unlock(phi->wait_eat), NULL);
		if (phi->has_eaten == 1)
		{
			hunger = 0;
			pthread_mutex_lock(phi->wait_monitoring);
			phi->has_eaten = 0;
			pthread_mutex_unlock(phi->wait_monitoring);
			timestamp_eat = get_timer(*phi->t0);
		}
		if (hunger - timestamp_eat > phi->time_to_die / 1000)
		{
			pthread_mutex_lock(phi->wait_monitoring);
			print_action(phi, " has died\n");
			phi->dead = 1;
			pthread_mutex_unlock(phi->wait_monitoring);
			return (pthread_mutex_unlock(phi->wait_eat), 1);
		}
		return (0);
}

void	*death_timer(void *death_arg)
{
	t_phi	*phi;
	time_t	timestamp_eat;
	time_t	hunger;

	phi = (t_phi *)death_arg;
	timestamp_eat = get_timer(*phi->t0);
	while (1)
	{
		pthread_mutex_lock(phi->wait_eat);
		hunger = get_timer(*phi->t0);
		if (death_condition(phi, timestamp_eat, hunger) != 0)
			return (NULL);
		pthread_mutex_unlock(phi->wait_eat);
	}
	return (NULL);
}

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

int	monitoring_loop(t_data *data)
{
	int	i;
	int	j;

	while (1)
	{
		i = -1;
		while (++i < data->number_of_philo)
		{
			pthread_mutex_lock(&data->wait_eat);
			if (data->phi[i].dead == 1)
			{
				j = -1;
				while (++j < data->number_of_philo)
				{
					data->phi[j].stop = 1;
				}
				pthread_mutex_unlock(&data->wait_eat);
				if (join_phi(data) != 0)
					return (1);
				return (0);
			}
			pthread_mutex_unlock(&data->wait_eat);
		}
	}
	return (0);
}
