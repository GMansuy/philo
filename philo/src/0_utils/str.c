/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:26:32 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/30 10:54:01 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_timer(time_t time, t_phi *phi)
{
	char	c;

	if (time > 9)
	{
		ft_timer(time / 10, phi);
	}
	c = (time % 10) + '0';
	if (!*(phi->dead))
		write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd, t_phi *phi)
{
	int	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	if (!*(phi->dead))
		write(fd, s, len);
}

static void	putnbr(unsigned int nbr, int fd, t_phi *phi)
{
	char	c;

	if (nbr > 9)
	{
		putnbr(nbr / 10, fd, phi);
	}
	c = (nbr % 10) + '0';
	if (!*(phi->dead))
		write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd, t_phi *phi)
{
	unsigned int	nbr;

	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = (unsigned int) -n;
	}
	else
		nbr = (unsigned int) n;
	putnbr(nbr, fd, phi);
}
