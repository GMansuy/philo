/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:24:46 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/04 15:52:08 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	forks_locker(t_phi *phi, int action)
{
	if (action == grab)
	{
		// print_action(phi, " enters function FORKS_LOCKER\n"); //	
		pthread_mutex_lock(phi->left_fork);
		print_action(phi, " has taken a fork\n");
		if (phi->number_of_philo == 1)
			return (pthread_mutex_unlock(phi->left_fork), 1);
		pthread_mutex_lock(phi->right_fork);
		print_action(phi, " has taken a fork\n");
	}
	else if (action == pose)
	{
		if (phi->number_of_philo != 1)
			pthread_mutex_unlock(phi->right_fork);
		pthread_mutex_unlock(phi->left_fork);
	}
	return (0);
}

int	go_eat(t_phi *phi)
{
	if (forks_locker(phi, grab) != 0)
		return (forks_locker(phi, pose), 1);
	print_action(phi, " is eating\n");
	phi->curr_eat++;
	pthread_mutex_lock(phi->wait_eat);
	if (phi->max_eat && phi->curr_eat >= phi->max_eat)
		return (forks_locker(phi, pose),
			pthread_mutex_unlock(phi->wait_eat), 1);
	phi->has_eaten = 1;
	pthread_mutex_unlock(phi->wait_eat);
	usleep(phi->time_to_eat);
	forks_locker(phi, pose);
	phi->state = sleeping;
	// if (phi->stop)
	// 	return (pthread_mutex_unlock(phi->wait_stop), 1);
	// pthread_mutex_unlock(phi->wait_stop);
	return (0);
}

int	go_sleep(t_phi *phi)
{
	print_action(phi, " is sleeping\n");
	usleep(phi->time_to_sleep);
	phi->state = thinking;
	// pthread_mutex_lock(phi->wait_stop);
	// if (phi->stop)
	// 	return (pthread_mutex_unlock(phi->wait_stop), 1);
	// pthread_mutex_unlock(phi->wait_stop);
	return (0);
}

int	go_think(t_phi *phi)
{
	int	time_to_think;

	time_to_think = phi->time_to_eat - phi->time_to_sleep;
	print_action(phi, " is thinking\n");
	if (time_to_think > 0)
		usleep(time_to_think);
	phi->state = eating;
	// pthread_mutex_lock(phi->wait_stop);
	// if (phi->stop)
	// 	return (pthread_mutex_unlock(phi->wait_stop), 1);
	// pthread_mutex_unlock(phi->wait_stop);
	return (0);
}
