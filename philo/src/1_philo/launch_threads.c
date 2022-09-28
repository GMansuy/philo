/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:03:57 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 16:06:56 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	th_eat(t_phi *phi)
{
	if (pthread_create(&phi->th, NULL, &eat_routine, (void *)phi) != 0)
		return (1);
	return (0);
}

int	th_sleep(t_phi *phi)
{
	if (pthread_create(&phi->th, NULL, &sleep_routine, (void *)phi) != 0)
		return (1);
	return (0);
}

// int	th_think(t_phi *phi)
// {
// 	if (pthread_create(&phi->th, NULL, &think_routine, (void *)phi) != 0)
// 		return (1);
// 	return (0);
// }