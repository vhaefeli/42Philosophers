/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:31:38 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/14 23:14:26 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo_times *t, int phase)
{
	if(t->philo_dead != 0)
		return(1);
	if(phase = 1 && t->t_to_die <= t->t_to_eat)
	{
		usleep(t->t_to_die);
		return (1);
	}
	if (phase = 2 && t->t_to_die <= t->t_to_eat + t->t_to_sleep)
	{
		usleep(t->t_to_die - t->t_to_eat);
		return (1);
	}
	else
		return (0);
}

void	pt_printf(char *msg, int moment, int philo_nb, t_philo_times *times)
{
	pthread_mutex_lock(&times.mutex_on_write);
	printf("%u %d %s\n", moment, philo_nb, msg);
	pthread_mutex_unlock(&times.mutex_on_write);
}

void	ft_philo_end(pthread_t **th, t_philo **philo_congr);
{
	int i;
	int	n;

	i = 0;
	n = philo_congr[i]->t->nbr_of_philo;
	while (i < n)
	{
		pthread_mutex_destroy(&philo_congr[i]->mutex_on_fork);
		if (pthread_join(th[i], NULL) != 0)
		{
			return 2;
		}
	}
	pthread_mutex_destroy(&philo_congr[0]->t->mutex_on_write);
	free (philo_congr);
	printf("Number of mails: %d\n", mails);
}