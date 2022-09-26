/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:08:13 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/26 17:31:00 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	free_threads(t_th *threads)
{
	free(threads->th);
}

void	free_all(t_data *philo)
{
	free_threads(philo->threads);
}
