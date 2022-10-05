/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:27:13 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/05 16:39:40 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
	}
	if (pthread_mutex_init(&data->wait_monitoring, NULL) != 0)
		return (2);
	if (pthread_mutex_init(&data->wait_eat, NULL) != 0)
		return (2);
	if (pthread_mutex_init(&data->wait_stop, NULL) != 0)
		return (2);
	return (0);
}

static void	phi_get_data(t_data *data, int i)
{
	int	last;

	last = !(i == data->number_of_philo - 1);
	data->phi[i].wait.left_fork = &data->forks[i];
	data->phi[i].wait.right_fork = &data->forks[(i + 1) * last];
	data->phi[i].t0 = &data->t0;
	data->phi[i].wait.wait_monitoring = &data->wait_monitoring;
	data->phi[i].wait.wait_eat = &data->wait_eat;
	data->phi[i].wait.wait_stop = &data->wait_stop;
	data->phi[i].wait.stop = 0;
	data->phi[i].args.time_to_eat = data->time_to_eat;
	data->phi[i].args.time_to_sleep = data->time_to_sleep;
	data->phi[i].args.time_to_die = data->time_to_die;
	data->phi[i].args.number_of_philo = data->number_of_philo;
	data->phi[i].args.max_eat = data->number_of_eat;
	data->phi[i].dead = 0;
	data->phi[i].has_eaten = 0;
	data->phi[i].curr_eat = 0;
	data->phi[i].last_meal = 0;
}

void	init_phi(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->phi[i].id = i;
		if (i % 2 == 0 && data->number_of_philo != 1)
		{
			data->phi[i].group = pair;
			data->phi[i].state = eating;
		}
		else
		{
			data->phi[i].group = impair;
			data->phi[i].state = eating;
		}
		phi_get_data(data, i);
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
	data->forks = NULL;
	data->phi = NULL;
}
