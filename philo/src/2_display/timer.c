/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:23:09 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 17:47:34 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	get_timer(struct timeval t0)
{
	struct timeval	timestamp;
	time_t			curr_time;

	gettimeofday(&timestamp, NULL);
	curr_time = ((timestamp.tv_sec - t0.tv_sec) * 1000000
			+ (timestamp.tv_usec - t0.tv_usec)) / 1000 ;
	if (curr_time < 10)
		printf("%d", 0);
	if (curr_time < 100)
		printf("%d", 0);
	if (curr_time < 1000)
		printf("%d", 0);
	printf("%ld ", curr_time);
}

void	init_timer(struct timeval *t0)
{
	gettimeofday(t0, NULL);
}
