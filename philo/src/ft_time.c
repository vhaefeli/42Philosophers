/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:17:11 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/21 15:44:13 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>
#include <unistd.h>
#include <philo.h>

unsigned int	get_current_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

unsigned int	chrono(int start_time)
{
	return (get_current_time_ms() - start_time);
}

void	fast_usleep(t_philo **philo, unsigned int now, unsigned int tsleep )
{
	while (philo[0]->t->philo_dead == 0)
	{
		if (now + tsleep <= get_current_time_ms())
			break ;
		usleep(100);
	}
}
