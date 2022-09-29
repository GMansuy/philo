/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_timer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:38:32 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 19:43:47 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*death_timer(void *death_arg)
{
	t_phi	*phi;
	time_t	timestamp_eat;
	time_t	hunger;
	
	phi = (t_phi *)death_arg;
	timestamp_eat = get_timer(*phi->t0);
	while (1)
	{
		hunger = get_timer(*phi->t0);
		if (phi->has_eaten == 1)
		{
			hunger = 0;
			phi->has_eaten = 0;
			timestamp_eat = get_timer(*phi->t0);
		}
		if (hunger - timestamp_eat > phi->time_to_die / 1000)
		{
			pthread_mutex_lock(phi->wait_monitoring);
			print_action(phi, " has died\n");
			*(phi->dead) = 1;
			pthread_mutex_unlock(phi->wait_monitoring);
			return (NULL);
		}
	}
	return (NULL);
}
