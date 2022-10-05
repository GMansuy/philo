/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:51:43 by gmansuy           #+#    #+#             */
/*   Updated: 2022/10/05 16:48:56 by gmansuy          ###   ########.fr       */
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

typedef struct s_wait
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*wait_monitoring;
	pthread_mutex_t	*wait_eat;
	pthread_mutex_t	*wait_stop;
	int				stop;
}	t_wait;

typedef struct s_args
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				number_of_philo;
	int				max_eat;
}	t_args;

typedef struct s_phi
{
	t_args			args;
	t_wait			wait;
	int				id;
	pthread_t		th;
	pthread_t		time_th;
	struct timeval	*t0;
	time_t			last_meal;
	int				state;
	int				group;
	int				curr_eat;
	int				has_eaten;
	int				dead;
}	t_phi;

typedef struct s_data
{
	t_phi			*phi;
	pthread_mutex_t	*forks;
	pthread_mutex_t	wait_monitoring;
	pthread_mutex_t	wait_eat;
	pthread_mutex_t	wait_stop;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	struct timeval	t0;
}	t_data;

//MAIN
int		philo_loop(t_data *data);

//UTILS
//str.c
size_t	ft_strlen(const char *s);
char	*philo_display(int time, char *str, int phid);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

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
//alloc.c
int		allocate_phi(t_data *data);
int		allocate_forks(t_data *data);
int		alloc_data(t_data *data);
t_data	*get_struct(void);
//parsing.c
int		parsing(int argc, char **argv, t_data *data);

//THREADS
//philo_loop.c
int		philo_loop(t_data *data);
//actions.c
int		pickup_forks(t_phi *phi);
int		go_eat(t_phi *phi);
int		go_sleep(t_phi *phi);
int		go_think(t_phi *phi);

//MONITORING
//monitoring_loop.c
void	*death_timer(void *death_arg);
int		monitoring_loop(t_data *data);
//timer.c
int		magic_usleep(int time, struct timeval t0, t_wait *w);
void	init_timer(struct timeval *t0);
time_t	get_timer(struct timeval t0);
void	print_action(struct timeval time, char *str, int phid, t_wait *w);
void	print_end(struct timeval time, char *str, int phid, t_wait *w);

#endif