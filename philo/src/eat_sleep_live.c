/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_live.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:20:06 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/16 17:33:53 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo **philo, int i, int n)
{
	if (i % 2 == 0)
	{
		pthread_mutex_lock(&philo[n]->mutex_on_fork);
		pt_printf("has taken a fork",
			chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
		pthread_mutex_lock(&philo[i]->mutex_on_fork);
		pt_printf("has taken a fork",
			chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
	}
	else
	{
		usleep(1000);
		pthread_mutex_lock(&philo[i]->mutex_on_fork);
		pt_printf("has taken a fork",
			chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
		pthread_mutex_lock(&philo[n]->mutex_on_fork);
		pt_printf("has taken a fork",
			chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
	}
	return (0);
}

int	philo_eat(t_philo **philo, int i)
{
	int	n;

	n = philo[i]->neighbour;
	take_forks(philo, i, n);
	philo[i]->t_alive = get_current_time_ms() + philo[i]->t->t_to_die;
	pt_printf("is eating", chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
	if (check_death(philo[i]->t, 1))
	{
		// pthread_mutex_unlock(&philo[n]->mutex_on_fork);
		// pthread_mutex_unlock(&philo[i]->mutex_on_fork);
		return (1);
	}
	usleep(philo[i]->t->t_to_eat * 1000);
	pthread_mutex_unlock(&philo[n]->mutex_on_fork);
	pthread_mutex_unlock(&philo[i]->mutex_on_fork);
	philo[i]->nb_meal_eaten++;
	if(philo[i]->nb_meal_eaten == philo[i]->t->nb_meal_max_eaten)
	{
		philo[i]->t->philo_full++;
		return (1);
	}
	return (0);
}

int	philo_sleep(t_philo **philo, int i)
{
	pt_printf("is sleeping", chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
	if (check_death(philo[i]->t, 2))
		return (1);
	usleep(philo[i]->t->t_to_sleep * 1008);
	return (0);
}

void	*eat_sleep_think(t_philo **philo, int i)
{
	int	n;

	n = philo[i]->neighbour;
	while(philo[i]->t_alive >= get_current_time_ms()
		&& philo[i]->t->philo_dead == 0)
	{
		if (philo_eat(philo, i))
			break;
		if (philo_sleep(philo, i))
			break;
		pt_printf("is thinking",
			chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
	}
	if (philo[i]->t_alive <= get_current_time_ms())
	{
		philo[i]->t->philo_dead = 1;
		pt_printfdead(chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
	}
	return (NULL);
}

void	*eat_sleep_live(void *argument)
{
	t_r_arg	*routine_arg;
	int				i;

	routine_arg = (t_r_arg *)argument;
	i = routine_arg->i;
		eat_sleep_think(routine_arg->philo_congr, i);
	return (NULL);
}
