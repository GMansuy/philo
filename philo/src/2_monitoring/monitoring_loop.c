/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:53:04 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/05 14:08:45 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
// int		death_condition(t_phi *phi, time_t *timestamp_eat, time_t *hunger)
// {
// 		pthread_mutex_lock(phi->wait.wait_eat);
// 		if (phi->has_eaten == 1)
// 		{
// 			*hunger = 0;
// 			phi->has_eaten = 0;
// 			*timestamp_eat = get_timer(*phi->t0);
// 		}
// 		pthread_mutex_unlock(phi->wait.wait_eat);
// 		if (*hunger - *timestamp_eat > phi->args.time_to_die / 1000)
// 		{
// 			phi->dead = 1;
// 			return (1);
// 		}
// 		return (0);
// }

// void	*death_timer(void *death_arg)
// {
// 	t_phi	*phi;
// 	time_t	timestamp_eat;
// 	time_t	hunger;

// 	phi = (t_phi *)death_arg;
// 	usleep(phi->args.number_of_philo * 10);
// 	timestamp_eat = get_timer(*phi->t0);
// 	while (1)
// 	{
// 		pthread_mutex_lock(phi->wait.wait_stop);
// 		if (phi->stop)
// 			return (pthread_mutex_unlock(phi->wait.wait_stop), NULL);
// 		pthread_mutex_unlock(phi->wait.wait_stop);
// 		hunger = get_timer(*phi->t0);
// 		if (death_condition(phi, &timestamp_eat, &hunger) != 0)
// 			return (pthread_mutex_unlock(phi->wait.wait_eat), NULL);
// 	}
// 	return (NULL);
// }

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
	time_t current_timer;

	current_timer = get_timer(*phi->t0);
	if ((int)current_timer - (int)phi->last_meal > phi->args.time_to_die / 1000)
		return (1);
	return (0);
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
			if (data->phi[i].curr_eat < data->number_of_eat)
				enough_meals = 0;
			if (is_dead(&data->phi[i]) == 1)
			{
				print_action(data->t0, "died\n", data->phi[i].id, &data->phi[i].wait);
				pthread_mutex_lock(&data->wait_monitoring);
				return (pthread_mutex_unlock(&data->wait_eat), stop_threads(data));
			}
			pthread_mutex_unlock(&data->wait_eat);
		}
		pthread_mutex_lock(&data->wait_eat);
		if (enough_meals == 1)
			return (pthread_mutex_unlock(&data->wait_eat), stop_threads(data));
		pthread_mutex_unlock(&data->wait_eat);
	}
	return (0);
}
