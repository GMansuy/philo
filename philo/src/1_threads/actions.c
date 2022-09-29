/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:24:46 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 20:07:07 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	forks_locker(t_phi *phi, int action)
{
	if (action == grab && !*(phi->dead))
	{
		pthread_mutex_lock(phi->left_fork);
		pthread_mutex_lock(phi->right_fork);
	}
	else if (action == pose && !*(phi->dead))
	{
		pthread_mutex_unlock(phi->left_fork);
		pthread_mutex_unlock(phi->right_fork);
	}
}

void	pickup_forks(t_phi *phi)
{	
	if (*(phi->dead))
		exit(0);
	forks_locker(phi, grab);
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " has taken a fork\n");
	pthread_mutex_unlock(phi->wait_monitoring);
}

void	go_eat(t_phi *phi)
{
	if (*(phi->dead))
		exit(0);
	pickup_forks(phi);
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " is eating\n");
	phi->curr_eat++;
	if (phi->max_eat && phi->curr_eat >= phi->max_eat)
		*(phi->dead) = 1;
	pthread_mutex_unlock(phi->wait_monitoring);
	usleep(phi->time_to_eat);
	phi->has_eaten = 1;
	forks_locker(phi, pose);
	phi->state = sleeping;
}

void	go_sleep(t_phi *phi)
{
	if (*(phi->dead))
		exit(0);
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " is sleeping\n");
	pthread_mutex_unlock(phi->wait_monitoring);
	usleep(phi->time_to_sleep);
	phi->state = thinking;
}

void	go_think(t_phi *phi)
{
	int	time_to_think;

	if (*(phi->dead))
		exit(0);
	time_to_think = phi->time_to_eat - phi->time_to_sleep;
	pthread_mutex_lock(phi->wait_monitoring);
	print_action(phi, " is thinking\n");
	pthread_mutex_unlock(phi->wait_monitoring);
	if (time_to_think > 0)
		usleep(time_to_think);
	phi->state = eating;
}
