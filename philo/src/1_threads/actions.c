/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:24:46 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 20:16:55 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	forks_locker(t_phi *phi, int action)
{
	if (action == grab && !phi->stop)
	{
		pthread_mutex_lock(phi->left_fork);
		pthread_mutex_lock(phi->right_fork);
	}
	else if (action == pose && !phi->stop)
	{
		pthread_mutex_unlock(phi->left_fork);
		pthread_mutex_unlock(phi->right_fork);
	}
	return (phi->stop);
}

int	pickup_forks(t_phi *phi)
{	
	if (phi->stop)
		return (1);
	if (forks_locker(phi, grab) != 0)
		return (1);
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " has taken a fork\n");
	pthread_mutex_unlock(phi->wait_monitoring);
	return (phi->stop);
}

int	go_eat(t_phi *phi)
{
	if (phi->stop)
		return (1);
	pickup_forks(phi);
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " is eating\n");
	phi->curr_eat++;
	pthread_mutex_unlock(phi->wait_monitoring);
	if (phi->max_eat && phi->curr_eat >= phi->max_eat)
		return (phi->dead = 1, 1);
	usleep(phi->time_to_eat);
	phi->has_eaten = 1;
	forks_locker(phi, pose);
	phi->state = sleeping;
	return (phi->stop);
}

int	go_sleep(t_phi *phi)
{
	if (phi->stop)
		return (1);
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " is sleeping\n");
	pthread_mutex_unlock(phi->wait_monitoring);
	usleep(phi->time_to_sleep);
	phi->state = thinking;
	return (phi->stop);
}

int	go_think(t_phi *phi)
{
	int	time_to_think;

	if (phi->stop)
		return (1);
	time_to_think = phi->time_to_eat - phi->time_to_sleep;
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " is thinking\n");
	pthread_mutex_unlock(phi->wait_monitoring);
	if (time_to_think > 0)
		usleep(time_to_think);
	phi->state = eating;
	return (phi->stop);
}
