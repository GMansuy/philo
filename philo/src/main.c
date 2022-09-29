/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:52:26 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 14:55:50 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_all(&data);
	if (parsing(argc, argv, &data) != 0)
		return (1);
	init_timer(&data.t0);
	if (alloc_data(&data) != 0)
		return (free_all(&data), 2);
	init_phi(&data);
	if (philo_loop(&data) != 0)
		return (free_all(&data), 3);
	return (free_all(&data), 0);
}
