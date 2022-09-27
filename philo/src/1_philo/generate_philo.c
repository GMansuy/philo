/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:59:29 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 12:21:45 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	allocate_th(t_data *philo, t_th *threads)
{
	threads->th = malloc(sizeof(pthread_t) * philo->number_of_philo);
	return (0);
}

int	generate_philo(t_data *philo)
{
	if (allocate_th(philo, philo->threads) != 0)
		return (1);
	if (init_forks(philo) != 0)
		return (2);
	return (0);
}
