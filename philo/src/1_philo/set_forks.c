/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:55:44 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 12:26:36 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	init_forks(t_data *philo)
{
	int	i;

	philo->forks = malloc (sizeof(int) * philo->number_of_philo + 1);
	if (!philo->forks)
		return (1);
	i = -1;
	while (++i < philo->number_of_philo)
		philo->forks[i] = i;
	return (0);
}
