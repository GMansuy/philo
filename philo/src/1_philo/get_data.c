/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:49:16 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 16:01:28 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_data	*get_struct(void)
{
	static t_data	data;

	return (&data);
}

int	allocate_phi(t_data *data)
{
	data->phi = malloc(sizeof(t_phi) * data->number_of_philo);
	if (!data->phi)
		return (msg("malloc : Error\n"), 1);
	init_phi(data);
	printf("phi allocated\n");
	return (0);
}

int	allocate_forks(t_data *data)
{
	data->forks = malloc(sizeof(t_phi) * data->number_of_philo);
	if (!data->forks)
		return (msg("malloc : Error\n"), 1);
	printf("forks allocated\n");
	return (0);
}
