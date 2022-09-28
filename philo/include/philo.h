/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:51:43 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/28 17:39:52 by gmansuy          ###   ########.fr       */
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

enum e_status {thinking, eating, sleeping, dead, waiting};
enum e_group {pair, impair};
enum e_action {init, grab, pose};

typedef struct s_phi
{
	pthread_t		th;
	int				id;
	int				state;
	int				group;
	struct timeval	hunger;
	int				has_eaten;
}	t_phi;

typedef struct s_data
{
	t_phi			*phi;
	pthread_mutex_t	*forks;
	pthread_mutex_t	wait_eat;
	pthread_mutex_t	wait_sleep;
	pthread_mutex_t	wait_think;
	pthread_mutex_t	wait_display;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;	
	int				prio;
	int				death;	
	struct timeval	t0;
}	t_data;

//init.c
void	init_all(t_data *data);
void	init_phi(t_data *data);
int		init_mutex(t_data *data);
//msg.c
int		msg(char *msg);
int		usage(void);
size_t	get_len(const char *s);
//free.c
void	destroy_mutex(t_data *data);
void	free_all(t_data *data);
//parsing.c
int		parsing(int argc, char **argv, t_data *data);

//PHILO
//generate_philo.c
int		generate_philo(t_data *data);
//get_data.c
int		allocate_phi(t_data *data);
int		allocate_forks(t_data *data);
t_data	*get_struct(void);
//launch_threads.c
int		th_eat(t_phi *phi, t_data *data);
int		th_sleep(t_phi *phi);
int		th_think(t_phi *phi);
void	*th_wait(void *arg);
//routines.c
void	*think_routine(t_data *data, t_phi *phi);
void	*eat_routine(void *arg);
void	*sleep_routine(void *arg);
//death.c
int		is_dead(t_phi *phi, t_data *data);
void	set_death_timer(t_phi *phi);

//set_forks.c
int		set_forks(int action, int info);

//DISPLAY
//timer.c
void	init_timer(struct timeval *t0);
void	print_timer(struct timeval t0);
time_t	get_timer(struct timeval t0);
#endif