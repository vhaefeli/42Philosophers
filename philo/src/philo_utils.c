/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:31:38 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/20 21:37:09 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pt_printf(char *msg, int moment, int philo_nb, t_philo_times *times)
{
	pthread_mutex_lock(&times->mutex_on_write);
	printf("%ums: %d %s\n", moment, philo_nb, msg);
	pthread_mutex_unlock(&times->mutex_on_write);
}

void	pt_printfdead(int moment, int philo_nb, t_philo_times *times)
{
	pthread_mutex_lock(&times->mutex_on_write);
	printf("%ums: %d died\n", moment, philo_nb);
	// pthread_mutex_unlock(&times->mutex_on_write);
}

int	error_arg(void)
{
	printf("Wrong arguments!\nPlease give: \nthe number_of_philosophers\n");
	printf("time_to_die\ntime_to_eat\ntime_to_sleep\n");
	printf("and if wanted: [number_of_times_each_philosopher_must_eat]\n");
	printf("Times in millisec and numbers > 0\nThank you\n");
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


