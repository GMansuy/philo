/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:53:04 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/05 16:48:20 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	stop_threads(t_data *data)
{
	int	j;

	j = -1;
	pthread_mutex_lock(&data->wait_stop);
	while (++j < data->number_of_philo)
		data->phi[j].wait.stop = 1;
	pthread_mutex_unlock(&data->wait_stop);
	pthread_mutex_unlock(&data->wait_monitoring);
	return (0);
}

int	is_dead(t_phi *phi)
{
	time_t	current_timer;

	current_timer = get_timer(*phi->t0);
	pthread_mutex_lock(phi->wait.wait_eat);
	if ((int)current_timer - (int)phi->last_meal > phi->args.time_to_die)
		return (1);
	return (pthread_mutex_unlock(phi->wait.wait_eat), 0);
}

int	monitoring_loop(t_data *data)
{
	int	i;
	int	enough_meals;

	while (1)
	{
		i = -1;
		enough_meals = 1 * (data->number_of_eat != 0);
		while (++i < data->number_of_philo)
		{
			pthread_mutex_lock(&data->wait_eat);
			enough_meals = (data->phi[i].curr_eat < data->number_of_eat);
			pthread_mutex_unlock(&data->wait_eat);
			if (is_dead(&data->phi[i]) == 1)
			{
				pthread_mutex_lock(&data->wait_monitoring);
				print_end(data->t0, "died\n", data->phi[i].id,
					&data->phi[i].wait);
				return (pthread_mutex_unlock(&data->wait_eat),
					stop_threads(data));
			}
		}
		if (enough_meals == 1)
			return (stop_threads(data));
	}
	return (0);
}
