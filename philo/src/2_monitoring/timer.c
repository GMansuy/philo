/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:23:09 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 16:28:18 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

time_t	get_timer(struct timeval t0)
{
	struct timeval	timestamp;
	time_t			curr_time;

	gettimeofday(&timestamp, NULL);
	curr_time = ((timestamp.tv_sec - t0.tv_sec) * 1000000
			+ (timestamp.tv_usec - t0.tv_usec)) / 1000 ;
	return (curr_time);
}

void	print_timer(struct timeval t0)
{
	struct timeval	timestamp;
	time_t			curr_time;

	gettimeofday(&timestamp, NULL);
	curr_time = ((timestamp.tv_sec - t0.tv_sec) * 1000000
			+ (timestamp.tv_usec - t0.tv_usec)) / 1000;
	if (curr_time < 10)
		ft_putnbr_fd(0, 1);
	if (curr_time < 100)
		ft_putnbr_fd(0, 1);
	if (curr_time < 1000)
		ft_putnbr_fd(0, 1);
	ft_timer(curr_time);
	write(1, " ", 1);
}

void	print_action(t_phi *phi, char *str)
{
	print_timer(*(phi->t0));
	(void)str;
	ft_putnbr_fd(phi->id, 1);
	ft_putstr_fd(str, 1);
}

void	init_timer(struct timeval *t0)
{
	gettimeofday(t0, NULL);
}
