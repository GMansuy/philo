/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:06:59 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/04 16:40:05 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *phi_arg)
{
	t_phi	*phi;

	phi = (t_phi *)phi_arg;
	if (pthread_create(&phi->time_th, NULL, &death_timer, phi) != 0)
			return (NULL);
	// print_action(phi, " --- created !---\n");
	while (1)
	{
		if (phi->state == eating && go_eat(phi) != 0)
			return (NULL);
		if (phi->state == sleeping && go_sleep(phi) != 0)
			return (NULL);
		if (phi->state == thinking && go_think(phi) != 0)
			return (NULL);
	}
	return (NULL);
}

int	philo_loop(t_data *data)
{
	int	i;
	int	j;
	int group;

	j = 2;
	if (init_mutex(data) != 0)
		return (1);
	group = pair;
	init_timer(&data->t0);
	while (j > 0)
	{
		i = -1;
		while (++i < data->number_of_philo)
		{
			if (data->phi[i].group == group && pthread_create(&data->phi[i].th, NULL,
				&routine, &data->phi[i]) != 0)
				return (2);
		}
		j--;
		group = impair;
	}
	monitoring_loop(data);
	return (0);
}
