/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:23:09 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/04 18:49:38 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	magic_usleep(t_phi *phi, int time)
{
	time = time * 1000;
	while (time--)
	{
		if (phi->stop)
			return (1);
		usleep(1000);
	}
	return (0);
}

time_t	get_timer(struct timeval t0)
{
	struct timeval	timestamp;
	time_t			curr_time;

	gettimeofday(&timestamp, NULL);
	curr_time = ((timestamp.tv_sec - t0.tv_sec) * 1000000
			+ (timestamp.tv_usec - t0.tv_usec)) / 1000 ;
	return (curr_time);
}

void	print_action(struct timeval time, char *str, int phid, t_wait *w)
{
	char *display;

	display = philo_display(get_timer(time), str, phid + 1);	
	pthread_mutex_lock(w->wait_monitoring);
	write (1, display, ft_strlen(display));
	pthread_mutex_unlock(w->wait_monitoring);
}

void	init_timer(struct timeval *t0)
{
	gettimeofday(t0, NULL);
}
