/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:08:13 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 17:48:47 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->wait_monitoring);
}

void	free_all(t_data *data)
{
	destroy_mutex(data);
	free(data->phi);
	free(data->forks);
}
