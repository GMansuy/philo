/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:08:13 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 16:31:55 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_mutex(t_data *data)
{
	int i;
	
	i = -1;
	while (++i < data->number_of_philo)
		pthread_mutex_destroy(&data->forks[i]);	
}

void	free_all(t_data *philo)
{
	free(philo->phi);
	free(philo->forks);
}
