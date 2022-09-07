/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:44:25 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/07 16:54:36 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <curses.h>
# include <pthread.h>

typedef struct s_philo
{
	unsigned int	philo_nb;
	pthread_mutex_t mutex_on_fork;
	unsigned int	time_eating;
	unsigned int	time_sleeping;
	unsigned int	time_alive;
	unsigned int	nb_meal_eaten;
} t_philo;

typedef struct s_philo_times
{
	unsigned int	nbr_of_philo;
	unsigned int	start_time;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	nb_meal_eaten;
} t_philo_times;

unsigned int	ft_atoui_check(const char *str);
long			get_current_time_ms(void);

#endif
