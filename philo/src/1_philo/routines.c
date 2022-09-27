/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:28:15 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 16:46:45 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*routine(void *arg)
{
	t_data	*data;
	t_phi	*phi;
	phi = (t_phi *) arg;
	
	sleep(1);	
	data = get_struct();
	(void) data;
	printf("thread : %d terminated\n", phi->id);
	return (NULL);
}
