/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:59:29 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 16:46:25 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	main_loop(t_data *data, t_phi *phi)
{
	int	i;
	
	init_mutex(data);
	while (!data->death)
	{
		i = -1;
		while (++i < data->number_of_philo)
		{
			printf("launching thread %d\n", phi[i].id);
			if (pthread_create(&phi[i].th, NULL, &routine,
				 (void *)&data->phi[i]) != 0)
				 return (1);
		}
		i = -1;
		while (++i < data->number_of_philo)
		{
			if (pthread_join(phi[i].th, NULL) != 0)
				 return (2);
		}
		data->death = 1;
	}
	destroy_mutex(data);
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
