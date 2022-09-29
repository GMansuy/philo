/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:45:08 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 15:43:58 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	usage(void)
{
	const char	*msg1 = "usage : ./philo [number_of_philosophers] ";
	const char	*msg2 = "[time_to_die] [time_to_eat] [time_to_sleep] [number";
	const char	*msg3 = "_of_times_each_philosopher_must_eat](optionnal)\n";

	write(2, msg1, ft_strlen(msg1));
	write(2, msg2, ft_strlen(msg2));
	write(2, msg3, ft_strlen(msg3));
	return (1);
}

int	msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}
