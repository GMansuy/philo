/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:27:13 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 12:18:09 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	init_threads(t_th *threads)
{
	threads->th = NULL;
}

void	init_all(t_data *philo)
{
	philo->number_of_philo = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->number_of_eat = 0;
	philo->forks = NULL;
	init_threads(philo->threads);
}
