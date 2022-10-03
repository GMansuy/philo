/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:23:09 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/03 13:30:06 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

time_t	get_timer(struct timeval t0)
{
	struct timeval	timestamp;
	time_t			curr_time;

	gettimeofday(&timestamp, NULL);
	curr_time = ((timestamp.tv_sec - t0.tv_sec) * 1000000
			+ (timestamp.tv_usec - t0.tv_usec)) / 1000 ;
	return (curr_time);
}

void	print_timer(t_phi *phi, struct timeval t0)
{
	struct timeval	timestamp;
	time_t			curr_time;

	gettimeofday(&timestamp, NULL);
	curr_time = ((timestamp.tv_sec - t0.tv_sec) * 1000000
			+ (timestamp.tv_usec - t0.tv_usec)) / 1000;
	if (!phi->stop && curr_time < 10)
		ft_putnbr_fd(0, 1, phi);
	if (!phi->stop && curr_time < 100)
		ft_putnbr_fd(0, 1, phi);
	if (!phi->stop && curr_time < 1000)
		ft_putnbr_fd(0, 1, phi);
	if (!phi->stop)
	{
		ft_timer(curr_time, phi);
		write(1, " ", !phi->stop);
	}
}

void	print_action(t_phi *phi, char *str)
{
	// pthread_mutex_lock(phi->wait_eat);
	print_timer(phi, *(phi->t0));
	ft_putnbr_fd(phi->id + 1, 1, phi);
	ft_putstr_fd(str, 1, phi);
	// pthread_mutex_unlock(phi->wait_eat);
}

void	init_timer(struct timeval *t0)
{
	gettimeofday(t0, NULL);
}
