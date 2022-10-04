/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:26:32 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/04 18:42:01 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

char	*philo_display(int time, char *str, int phid)
{
	char 	*time_string;
	char 	*phid_string;
	char	*tmp_display;
	char	*display;

	time_string = ft_itoa(time);
	phid_string = ft_itoa(phid);
	tmp_display = ft_strjoin(time_string, phid_string);
	display = ft_strjoin(tmp_display, str);
	free(time_string);
	free(phid_string);
	free(tmp_display);
	return (display);
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
	write(fd, s, len * !phi->stop);
}

static void	putnbr(unsigned int nbr, int fd, t_phi *phi)
{
	char	c;

	if (nbr > 9)
	{
		putnbr(nbr / 10, fd, phi);
	}
	c = (nbr % 10) + '0';
	write(fd, &c, !phi->stop);
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
