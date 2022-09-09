/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:17:11 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/09 08:15:36 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>
#include "../philo.h"

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

int	check_death(t_philo_times t, int phase)
{

	if(phase = 1 && t.t_to_die <= t.t_to_eat)
	{
		usleep(t.t_to_die);
		return (1);
	}
	if (phase = 2 && t.t_to_die <= t.t_to_eat + t.t_to_sleep)
	{
		usleep(t.t_to_die - t.t_to_eat);
		return (1);
	}
	else
		return (0);
}
