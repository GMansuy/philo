/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:35:04 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/26 16:49:36 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long	ft_atol(char *nptr)
{
	int			i;
	int			neg;
	long long	value;

	i = 0;
	neg = 0;
	if (nptr[i] == '-' && nptr[i + 1])
	{
		if (nptr[i] == '-')
			neg++;
		i++;
	}
	value = 0;
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (msg("Error : invalid argument\n"), 0);
		value += nptr[i] - '0';
		if (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
			value *= 10;
		i++;
	}
	if (neg % 2 != 0)
		value = -value;
	return (value);
}

int	get_int_from_args(char *str)
{
	long long	value;

	if (get_len(str) > 11)
		return (msg("Error : argument is too big\n"), 0);
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	else
		return ((int)value);
}

int	parsing(int argc, char **argv, t_data *philo)
{
	if (argc < 5 || argc > 6)
		return (usage());
	philo->number_of_philo = get_int_from_args(argv[1]);
	if (!philo->number_of_philo)
		return (2);
	philo->time_to_die = get_int_from_args(argv[2]);
	if (!philo->time_to_die)
		return (3);
	philo->time_to_eat = get_int_from_args(argv[3]);
	if (!philo->time_to_eat)
		return (4);
	philo->time_to_sleep = get_int_from_args(argv[4]);
	if (!philo->time_to_sleep)
		return (5);
	if (argc == 6)
	{
		philo->number_of_eat = get_int_from_args(argv[5]);
		if (!philo->number_of_eat)
			return (6);
	}
	return (0);
}
