/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:59:29 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 12:57:58 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// static int main_loop(t_data *philo)
// {
// 	int	i;
	
// 	while (!philo->death)
// 	{
// 		i = 0;
// 		while (i < philo->number_of_eat)
// 		{
// 			i++;
// 		}
// 	}
// 	return (0);
// }

static int	allocate_phi(t_data *philo)
{
	philo->phi = malloc(sizeof(t_phi) * philo->number_of_philo);
	if (!philo->phi)
		return (1);
	init_phi(philo);
	return (0);
}

int	generate_philo(t_data *philo)
{
	if (allocate_phi(philo) != 0)
		return (1);
	if (init_forks(philo) != 0)
		return (2);
	// main_loop(philo);
	return (0);
}
