/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:35:04 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/06 18:01:27 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	is_neg(t_data *data)
{
	if (data->number_of_eat && data->number_of_eat < 0)
		return (1);
	return ((data->number_of_eat < 0) || (data->number_of_philo < 0)
		|| (data->time_to_eat < 0) || (data->time_to_sleep < 0)
		|| (data->time_to_die < 0));
}

static long long	ft_atol(char *nptr)
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
			return (0);
		value += nptr[i] - '0';
		if (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
			value *= 10;
		i++;
	}
	if (neg % 2 != 0)
		value = -value;
	return (value);
}

static int	get_int_from_args(char *str)
{
	long long	value;

	if (ft_strlen(str) > 11)
		return (0);
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	else
		return ((int)value);
}

int	parsing(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		return (usage());
	data->number_of_philo = get_int_from_args(argv[1]);
	if (data->number_of_philo <= 0 || data->number_of_philo > 200)
		return (msg("Error : invalid argument\n"), 1);
	data->time_to_die = get_int_from_args(argv[2]);
	if (data->time_to_die < 60)
		return (msg("Error : invalid argument\n"), 1);
	data->time_to_eat = get_int_from_args(argv[3]);
	if (data->time_to_eat < 60)
		return (msg("Error : invalid argument\n"), 1);
	data->time_to_sleep = get_int_from_args(argv[4]);
	if (data->time_to_sleep < 60)
		return (msg("Error : invalid argument\n"), 1);
	if (argc == 6)
	{
		data->number_of_eat = get_int_from_args(argv[5]);
		if (data->number_of_eat <= 0)
			return (msg("Error : invalid argument\n"), 1);
	}
	if (is_neg(data) != 0)
		return (msg("Error : invalid argument\n"), 1);
	return (0);
}
