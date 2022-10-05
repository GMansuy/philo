/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:26:32 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/05 16:21:54 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

static void	putnbr(unsigned int nbr, int fd)
{
	char	c;

	if (nbr > 9)
	{
		putnbr(nbr / 10, fd);
	}
	c = (nbr % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = (unsigned int) -n;
	}
	else
		nbr = (unsigned int) n;
	putnbr(nbr, fd);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	print_action(struct timeval time, char *str, int phid, t_wait *w)
{
	pthread_mutex_lock(w->wait_monitoring);
	if (!w->stop)
	{
		ft_putnbr_fd((int)get_timer(time), 1);
		write(1, " ", 1);
		ft_putnbr_fd(phid + 1, 1);
		write(1, " ", 1);
		ft_putstr_fd(str, 1);
	}
	pthread_mutex_unlock(w->wait_monitoring);
}

void	print_end(struct timeval time, char *str, int phid, t_wait *w)
{
	if (!w->stop)
	{
		ft_putnbr_fd((int)get_timer(time), 1);
		write(1, " ", 1);
		ft_putnbr_fd(phid + 1, 1);
		write(1, " ", 1);
		ft_putstr_fd(str, 1);
	}
}
