/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:03:13 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 17:56:56 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	is_dead(t_phi *phi, t_data *data)
{
	struct timeval	timestamp;
	time_t			curr_time;

	gettimeofday(&timestamp, NULL);
	curr_time = ((timestamp.tv_sec - phi->hunger.tv_sec) * 1000000
			+ (timestamp.tv_usec - phi->hunger.tv_usec)) / 1000 ;
	if (curr_time > data->time_to_die)
	{
		print_timer(data->t0);
		printf("%d is dead\n", phi->id);
		return (0);
	}
	return (1);

}

void	set_death_timer(t_phi *phi)
{
	gettimeofday(&phi->hunger, NULL);
}