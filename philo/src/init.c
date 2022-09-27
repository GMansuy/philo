/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:27:13 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 15:58:25 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_phi(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->phi->state = thinking;
		if ((i + 1) % 2 == 0)
			data->phi->group = pair;
		else
			data->phi->group = impair;
		i++;
	}
}

void	init_all(t_data *data)
{
	data->number_of_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->number_of_eat = 0;
	data->death = 0;
	data->forks = NULL;
	data->phi = NULL;
}
