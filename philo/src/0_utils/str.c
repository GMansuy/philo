/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:26:32 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/05 14:12:35 by gmansuy          ###   ########.fr       */
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
	if (!time_string)
		return (NULL);
	phid_string = ft_itoa(phid);
	if (!phid_string)
		return (NULL);
	tmp_display = ft_strjoin(time_string, phid_string);
	if (!tmp_display)
		return (NULL);
	display = ft_strjoin(tmp_display, str);
	if (!display)
		return (NULL);
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

void	print_action(struct timeval time, char *str, int phid, t_wait *w)
{
	char *display;

	display = philo_display(get_timer(time), str, phid + 1);
	if (!display)
		return ;
	pthread_mutex_lock(w->wait_monitoring);
	write(1, display, ft_strlen(display) * !w->stop);
	pthread_mutex_unlock(w->wait_monitoring);
	free(display);
}

