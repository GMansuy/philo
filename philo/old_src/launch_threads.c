/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:03:57 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 17:39:10 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*th_wait(void *arg)
{
	(void) arg;
	return (NULL);
}

// int	th_eat(t_phi *phi, t_data *data)
// {
// 	if (pthread_create(&phi->th, NULL, &eat_routine, (void *)phi) != 0)
// 		return (1);
// 	return (0);
// }

// int	th_sleep(t_phi *phi)
// {
// 	if (pthread_create(&phi->th, NULL, &sleep_routine, (void *)phi) != 0)
// 		return (1);
// 	return (0);
// }

// int	th_think(t_phi *phi)
// {
// 	if (pthread_create(&phi->th, NULL, &think_routine, (void *)phi) != 0)
// 		return (1);
// 	return (0);
// }