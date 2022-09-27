/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:27:13 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 12:57:42 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_phi(t_data *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philo)
	{
		philo->phi->forks = 1;
		philo->phi->state = thinking;
		if ((i + 1) % 2 == 0)
			philo->phi->group = pair;
		else
			philo->phi->group = impair;
		i++;
	}
}

void	init_all(t_data *philo)
{
	philo->number_of_philo = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->number_of_eat = 0;
	philo->forks = NULL;
	philo->phi = NULL;
}
