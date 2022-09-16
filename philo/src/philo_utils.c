/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:31:38 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/16 16:02:30 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo_times *t, int phase)
{
	if(t->philo_dead != 0)
	{
		printf("dead\n");
		return(1);
	}
		return(1);
	if(phase == 1 && t->t_to_die <= t->t_to_eat)
	{
		usleep(t->t_to_die * 1000);
		return (1);
	}
	if (phase == 2 && t->t_to_die <= t->t_to_eat + t->t_to_sleep)
	{
		usleep(t->t_to_die - t->t_to_eat * 1000);
		return (1);
	}
	else
		return (0);
}

void	pt_printf(char *msg, int moment, int philo_nb, t_philo_times *times)
{
	pthread_mutex_lock(&times->mutex_on_write);
	printf("%u %d %s\n", moment, philo_nb, msg);
	pthread_mutex_unlock(&times->mutex_on_write);
}

int	error_arg(void)
{
	printf("wrong arguments!\nPlease give the number_of_philosophers");
	printf(" time_to_die time_to_eat time_to_sleep");
	printf(" and if wanted: [number_of_times_each_philosopher_must_eat]\n");
	printf("Times in millisec\nThank you\n");
	return (1);
}

int	philo_end(pthread_t *th, t_philo **philo_congr, t_r_arg **rout_arg)
{
	int i;
	int	n;

	i = 0;
	n = philo_congr[i]->t->nbr_of_philo;
	while (i < n)
	{
		printf("clean i %d\n",i);
		if (pthread_join(th[i], NULL) != 0)
		{
			printf("error in joining thread\n");
			return (2);
		}
		pthread_mutex_destroy(&philo_congr[i]->mutex_on_fork);
		free(philo_congr[i]);
		free(rout_arg[i]);
		i++;
	}
	pthread_mutex_destroy(&philo_congr[0]->t->mutex_on_write);
	free(philo_congr);
	free(rout_arg);
	free(th);
	return (0);
}
