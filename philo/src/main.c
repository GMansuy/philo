/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:52:26 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/26 11:02:27 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
	int	i;
	
	i = 0;
	while (i++ < 1000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	*value = mails / 1000;
	return ((void *)&value);
}

int	main(int argc, char **argv)
{
	pthread_t th[4];
	int	i;
	int *ptr;

	(void) argc;
	(void) argv;
	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			return (1);
		printf("Thread %d started\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(th[i], (void **)&ptr) != 0)
			return (1);
		printf("Thread %d finished ", i);
		printf("-- value =  %d\n", *ptr);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("%d\n", mails);
	return (0);
}