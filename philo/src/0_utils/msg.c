/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:45:08 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/29 10:02:51 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

size_t	get_len(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	usage(void)
{
	const char	*msg1 = "usage : ./philo [number_of_philosophers] ";
	const char	*msg2 = "[time_to_die] [time_to_eat] [time_to_sleep] [number";
	const char	*msg3 = "_of_times_each_philosopher_must_eat](optionnal)\n";

	write(2, msg1, get_len(msg1));
	write(2, msg2, get_len(msg2));
	write(2, msg3, get_len(msg3));
	return (1);
}

int	msg(char *msg)
{
	write(2, msg, get_len(msg));
	return (1);
}
