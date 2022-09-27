/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:59:29 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 16:01:34 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	main_loop(t_data *data, t_phi *phi)
{
	int	i;

	while (!data->death)
	{
		i = -1;
		while (++i < data->number_of_philo)
		{
			pthread_create(&phi[i].th, NULL, &routine, (void *)data->phi);
		}
		i = -1;
		while (++i < data->number_of_philo)
		{
			pthread_join(phi[i].th, NULL);
		}
		data->death = 1;
	}
	return (0);
}

int	generate_philo(t_data *data)
{
	if (allocate_phi(data) != 0)
		return (1);
	if (allocate_forks(data) != 0)
		return (2);
	main_loop(data, data->phi);
	return (0);
}
