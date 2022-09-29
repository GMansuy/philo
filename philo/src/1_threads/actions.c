/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:24:46 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 16:55:51 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	forks_locker(t_phi *phi, int action)
{
	if (action == grab)
	{
		pthread_mutex_lock(phi->left_fork);
		pthread_mutex_lock(phi->right_fork);
	}
	else if (action == pose)
	{
		pthread_mutex_unlock(phi->left_fork);
		pthread_mutex_unlock(phi->right_fork);		
	}
}

void	pickup_forks(t_phi *phi)
{	
	forks_locker(phi, grab);
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " has taken a fork\n");
	pthread_mutex_unlock(phi->wait_monitoring);
}

void	go_eat(t_phi *phi)
{
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " is eating\n");
	pthread_mutex_unlock(phi->wait_monitoring);
	usleep(phi->time_to_eat);
	forks_locker(phi, pose);
}

void	go_sleep(t_phi *phi)
{
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " is sleeping\n");
	pthread_mutex_unlock(phi->wait_monitoring);
	usleep(phi->time_to_sleep);
}

void	go_think(t_phi *phi)
{
	int	time_to_think;

	time_to_think = phi->time_to_eat - phi->time_to_sleep;
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " is thinking\n");
	pthread_mutex_unlock(phi->wait_monitoring);
	if (time_to_think > 0)
		usleep(time_to_think);
}