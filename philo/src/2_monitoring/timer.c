/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:23:09 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/05 14:13:27 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	magic_usleep(int time, struct timeval t0, t_wait *w)
{
	time_t	current_time;
	time_t	stop_time;

	current_time = get_timer(t0);
	stop_time = current_time + time;
	while (get_timer(t0) < stop_time)
	{
		pthread_mutex_lock(w->wait_stop);
		if (w->stop)
			return (pthread_mutex_unlock(w->wait_stop), 1);
		pthread_mutex_unlock(w->wait_stop);
		usleep(1);
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

void	init_timer(struct timeval *t0)
{
	gettimeofday(t0, NULL);
}
