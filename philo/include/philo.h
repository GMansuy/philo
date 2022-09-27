/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:51:43 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/27 12:16:32 by gmansuy          ###   ########.fr       */
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
	pthread_t		*th;
	pthread_mutex_t	mutex;
}	t_th;

typedef struct s_data
{
	struct timeval	t0;
	int				*forks;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;	
	t_th			*threads;
}	t_data;

//init.c
void	init_all(t_data *philo);
//msg.c
int		msg(char *msg);
int		usage(void);
size_t	get_len(const char *s);
//free.c
void	free_all(t_data *philo);
//parsing.c
int		parsing(int argc, char **argv, t_data *philo);

//PHILO
//generate_philo.c
int		generate_philo(t_data *philo);
//set_forks.c
int		init_forks(t_data *philo);
//DISPLAY
//timer.c
void	init_timer(struct timeval *t0);
void	get_timer(struct timeval t0);
#endif