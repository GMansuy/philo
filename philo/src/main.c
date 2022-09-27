/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:52:26 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 12:14:34 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	philo;
	t_th	threads;

	philo.threads = &threads;
	init_all(&philo);
	if (parsing(argc, argv, &philo) != 0)
		return (1);
	init_timer(&philo.t0);
	if (generate_philo(&philo) != 0)
		return (free_all(&philo), 2);
	return (free_all(&philo), 0);
}
