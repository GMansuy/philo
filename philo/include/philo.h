/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:51:43 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/26 16:54:32 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_th
{
	pthread_t 		*th;
	pthread_mutex_t mutex;
}	t_th;

typedef struct s_data
{
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_eat;	
	t_th	*threads;
}	t_data;



//init.c
void	init_all(t_data *philo);
//msg.c
int		msg(char *msg);
int		usage(void);
size_t	get_len(const char *s);
//------------------------------------------ PARSING
//parsing.c
int		parsing(int argc, char **argv, t_data *philo);

#endif