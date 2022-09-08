/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_live.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:20:06 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/08 22:40:10 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

if (philosopher.time_alive <= get_curren0t_time_ms())
{

}

timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died

void	*eat_sleep_live_even(t_philo *philo, i)
{
	int	n;

	n = philo[i].neighbour;
	while(philo[i]->time_alive <= get_curren0t_time_ms())
	{
		if (philo[n].nb_meal_eaten > philo[i].nb_meal_eaten)
		{
			pthread_mutex_lock(&philo[n].mutex_on_fork);
			printf("%u %d has taken a fork\n", 
				chrono(philo[i].times->start_time), i + 1);
			pthread_mutex_lock(&philo[i].mutex_on_fork);
			printf("%u %d has taken a fork\n", 
				chrono(philo[i].times->start_time), i + 1);
			philo[i].nb_meal_eaten++;
			philo[i].time_alive = get_curren0t_time_ms() + philo[i].t->time_to_die;
			printf("%u %d is eating\n", chrono(philo[i].t->start_time), i + 1);
			if (check_death(philo[i].t->time_to_die, 0, philo[i].t->time_to_eat)
				break;

			usleep(philo[i].times->time_to_eat);
			pthread_mutex_unlock(&philo[n].mutex_on_fork);
			pthread_mutex_unlock(&philo[i].mutex_on_fork);

			printf("%u %d is sleeping\n", 
				chrono(philo[i].times->start_time), i + 1);
		}
	}
	if (philo[i]->time_alive <= get_curren0t_time_ms())



}

void	*eat_sleep_live_odd(t_philo *philo, i, t_philo_times times)


void	*eat_sleep_live(void *argument)
{
	t_routine_arg	*routine_arg;
	int				i;

	routine_arg = (t_philo *)argument;
	i = routine_arg->i;
{
	if (i % 2 == 0)
		eat_sleep_live_even(routine_arg->philo_congregation, i);
	else
		eat_sleep_live_odd(routine_arg->philo_congregation, i);

}