/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:06:59 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 20:17:28 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *phi_arg)
{
	t_phi	*phi;

	phi = (t_phi *)phi_arg;
	while (1)
	{
		if (phi->state == eating)
			go_eat(phi);
		if (phi->state == sleeping)
			go_sleep(phi);
		if (phi->state == thinking)
			go_think(phi);
	}
	return (NULL);
}

int	philo_loop(t_data *data)
{
	int	i;

	i = -1;
	if (init_mutex(data) != 0)
		return (1);
	while (++i < data->number_of_philo)
	{
		if (pthread_create(&data->phi[i].th, NULL, &routine,
				&data->phi[i]) != 0)
			return (2);
		if (pthread_create(&data->phi[i].time_th, NULL, &death_timer,
				&data->phi[i]) != 0)
			return (3);
		if (pthread_detach(data->phi[i].th))
			return (4);
		if (pthread_detach(data->phi[i].time_th))
			return (5);
	}
	monitoring_loop(data);
	return (0);
}
