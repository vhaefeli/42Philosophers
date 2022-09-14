/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_live.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:20:06 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/14 23:15:04 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"





int	philo_eat(t_philo **philo, int i)
{
	int	n;

	n = philo[i]->neighbour;
	pthread_mutex_lock(&philo[n].mutex_on_fork);
	pt_printf("has taken a fork",
		chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
	pthread_mutex_lock(&philo[i]->mutex_on_fork);
	pt_printf("has taken a fork",
		chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
	philo[i]->nb_meal_eaten++;
	philo[i]->time_alive = get_current_time_ms() + philo[i]->t->t_to_die;
	pt_printf("is eating", chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
	if (check_death(philo[i]->t, 1)
		return (1);
	usleep(philo[i]->t->t_to_eat);
	pthread_mutex_unlock(&philo[n].mutex_on_fork);
	pthread_mutex_unlock(&philo[i]->mutex_on_fork);
	if(philo[i]->nb_meal_eaten == philo[i]->t->nb_meal_max_eaten)
	{
		philo[i]->philo_full++;
		return (1);
	}
	return (0);
}

int	philo_sleep(t_philo **philo, int i)
{
	pt_printf("is sleeping", chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
	if (check_death(philo[i]->t, 2)
		return (1);
	usleep(philo[i]->t->t_to_sleep);
	return (0);
}

void	*eat_sleep_live_even(t_philo **philo, int i)
{
	int	n;

	n = philo[i]->neighbour;
	while(philo[i]->time_alive <= get_current_time_ms()
		&& philo[i]->t->philo_dead == 0)
	{
		if (philo[n]->nb_meal_eaten > philo[i]->nb_meal_eaten)
		{
			if (philo_eat(philo, i))
				break;
			if (philo_sleep(philo, i))
				break;
			pt_printf("is thinking",
				chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
		}
	}
	if (philo[i]->time_alive <= get_current_time_ms())
	{
		pt_printf("died",
				chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
		philo[i]->t->philo_dead = 1;
	}
}

void	*eat_sleep_live_odd(t_philo **philo, int i, t_philo_times times)
{
	int	n;

	n = philo[i]->neighbour;
	while(philo[i]->time_alive <= get_current_time_ms()
		&& philo[i]->t->philo_dead == 0)
	{
		if (philo[n]->nb_meal_eaten == philo[i]->nb_meal_eaten)
		{
			if (philo_eat(philo, i))
				break;
			if (philo_sleep(philo, i))
				break;
			pt_printf("is thinking",
				chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
		}
	}
	if (philo[i]->time_alive <= get_current_time_ms())
	{
		pt_printf("died",
				chrono(philo[i]->t->start_time), i + 1, philo[i]->t);
		philo[i]->t->philo_dead = 1;
	}
}

void	*eat_sleep_live(void *argument)
{
	t_routine_arg	*routine_arg;
	int				i;

	routine_arg = (t_routine_arg * )argument;
	i = routine_arg->i;
	if (i % 2 == 0)
		eat_sleep_live_even(routine_arg->philo_congregation, i);
	else
		eat_sleep_live_odd(routine_arg->philo_congregation, i);
}