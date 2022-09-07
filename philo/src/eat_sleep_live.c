/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_live.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:20:06 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/07 18:11:56 by vhaefeli         ###   ########.fr       */
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

void	ft_shift(int i, int nb, )
{
	if (nb % 2 == 0)
		if (i % 2 == 1)
			usleep(1);
}

void	*eat_sleep_live(t_philo *philo, i, t_philo_times times)
{
	int	n;

	if (i == times.nbr_of_philo)
		n = 0;
	else
		n = i + 1;
	if(philo[i].nb_meal_eaten == 0 || times.nbr_of_phile % 2 != 0)
		ft_shift(i, times.nbr_of_philo, philo);
	while(philosopher.time_alive <= get_curren0t_time_ms())
	{
		pthread_mutex_lock(&philo[i].mutex_on_fork);
		if (pthread_mutex_lock(&philo[n].mutex_on_fork) != 0)
			pthread_mutex_unlock(&philo[i].mutex_on_fork);
		printf("%u ", chrono(times.start_time), ))
		usleep(times.time_to_eat);
		pthread_mutex_unlock(&philo[i].mutex_on_fork);
		if (i == times.nbr_of_philo)
			pthread_mutex_unlock(&philo[0].mutex_on_fork);
		else
			pthread_mutex_unlock(&philo[i + 1].mutex_on_fork);


}
