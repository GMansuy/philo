/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:53:04 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 20:01:29 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	monitoring_loop(t_data *data)
{
	int	i;

	i = -1;
	while (1)
	{
		if (data->end_death == 1)
			return (0);
		if (data->end_eat == 1)
			return (0);
	}
	return (0);
}
