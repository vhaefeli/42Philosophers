/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:13:49 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/20 21:19:11 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(t_philo_times *t)
{
	if (t->nbr_of_philo == 0)
		return (1);
	if (t->t_to_die == 0)
		return (1);
	if (t->t_to_eat == 0)
		return (1);
	if (t->t_to_sleep == 0)
		return (1);
	if (t->nb_meal_max_eaten == 0)
		return (1);
	else 
		return (0);
}

int	check_all_alive(t_philo **philo)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = philo[0]->t->nbr_of_philo;
	while (philo[i]->t_alive > get_current_time_ms() && 
				philo[0]->t->philo_full < n)
	{
		i++;
		if (i == n)
			i = 0;
	}
	if (philo[0]->t->philo_full == n)
		printf("they have all eaten enough for all their live");
	else
	{
		philo[i]->t->philo_dead = 1;
		pt_printfdead(chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
	}
	return(0);
}