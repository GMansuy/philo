/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:24:46 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/06 18:01:39 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	forks_pose(t_wait *w)
{
	pthread_mutex_unlock(w->right_fork);
	pthread_mutex_unlock(w->left_fork);
	return (0);
}

static int	forks_grab(t_phi *phi)
{
	if (phi->args.number_of_philo == 1)
		return (print_action(*phi->t0, "has taken a fork\n",
				phi->id, &phi->wait), 1);
	else if (phi->group == pair)
	{
		pthread_mutex_lock(phi->wait.right_fork);
		print_action(*phi->t0, "has taken a fork\n", phi->id, &phi->wait);
		pthread_mutex_lock(phi->wait.left_fork);
		print_action(*phi->t0, "has taken a fork\n", phi->id, &phi->wait);
	}
	else
	{
		pthread_mutex_lock(phi->wait.left_fork);
		print_action(*phi->t0, "has taken a fork\n", phi->id, &phi->wait);
		pthread_mutex_lock(phi->wait.right_fork);
		print_action(*phi->t0, "has taken a fork\n", phi->id, &phi->wait);
	}	
	return (0);
}

int	go_eat(t_phi *phi)
{	
	if (forks_grab(phi) != 0)
		return (forks_pose(&phi->wait), 1);
	print_action(*phi->t0, "is eating\n", phi->id, &phi->wait);
	pthread_mutex_lock(phi->wait.wait_eat);
	phi->curr_eat++;
	phi->last_meal = get_timer(*phi->t0);
	pthread_mutex_unlock(phi->wait.wait_eat);
	magic_usleep(phi->args.time_to_eat, *phi->t0, &phi->wait);
	forks_pose(&phi->wait);
	phi->state = sleeping;
	return (0);
}

int	go_sleep(t_phi *phi)
{
	print_action(*phi->t0, "is sleeping\n", phi->id, &phi->wait);
	magic_usleep(phi->args.time_to_sleep, *phi->t0, &phi->wait);
	phi->state = thinking;
	return (0);
}

int	go_think(t_phi *phi)
{
	int	time_to_think;

	time_to_think = phi->args.time_to_eat - phi->args.time_to_sleep;
	print_action(*phi->t0, "is thinking\n", phi->id, &phi->wait);
	if (time_to_think >= 0)
		magic_usleep(time_to_think, *phi->t0, &phi->wait);
	phi->state = eating;
	return (0);
}
