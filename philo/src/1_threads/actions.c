/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:24:46 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/04 18:50:24 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	forks_locker(t_phi *phi, int action)
{
	if (action == grab)
	{
		pthread_mutex_lock(phi->forks.left_fork);
		print_action(*phi->t0, "has taken a fork\n", phi->id, &phi->wait);
		if (phi->args.number_of_philo == 1)
			return (pthread_mutex_unlock(phi->forks.left_fork), 1);
		pthread_mutex_lock(phi->forks.right_fork);
		print_action(*phi->t0, "has taken a fork\n", phi->id, &phi->wait);
	}
	else if (action == pose)
	{
		if (phi->args.number_of_philo != 1)
			pthread_mutex_unlock(phi->forks.right_fork);
		pthread_mutex_unlock(phi->forks.left_fork);
	}
	return (0);
}

int	go_eat(t_phi *phi)
{	
	if (forks_locker(phi, grab) != 0)
		return (forks_locker(phi, pose), 1);
	print_action(*phi->t0, "is eating\n", phi->id, &phi->wait);
	phi->curr_eat++;
	pthread_mutex_lock(phi->wait.wait_eat);
	if (phi->args.max_eat && phi->curr_eat >= phi->args.max_eat)
		return (forks_locker(phi, pose),
			pthread_mutex_unlock(phi->wait.wait_eat), 1);
	phi->has_eaten = 1;
	pthread_mutex_unlock(phi->wait.wait_eat);
	usleep(phi->args.time_to_eat);
	forks_locker(phi, pose);
	phi->state = sleeping;
	return (0);
}

int	go_sleep(t_phi *phi)
{
	print_action(*phi->t0, "is sleeping\n", phi->id, &phi->wait);
	usleep(phi->args.time_to_sleep);
	phi->state = thinking;
	return (0);
}

int	go_think(t_phi *phi)
{
	int	time_to_think;

	time_to_think = phi->args.time_to_eat - phi->args.time_to_sleep;
	print_action(*phi->t0, "is thinking\n", phi->id, &phi->wait);
	if (time_to_think > 0)
		usleep(time_to_think);
	phi->state = eating;
	return (0);
}
