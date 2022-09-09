/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:44:25 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/09 11:32:59 by vhaefeli         ###   ########.fr       */
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
	unsigned int	neighbour;
	pthread_mutex_t mutex_on_fork;
	// unsigned int	time_eating;
	// unsigned int	time_sleeping;
	unsigned int	t_alive;
	unsigned int	nb_meal_eaten;
	t_philo_times	*t;
} t_philo;

typedef struct s_philo_times
{
	unsigned int	nbr_of_philo;
	unsigned int	start_time;
	unsigned int	t_to_die;
	unsigned int	t_to_eat;
	unsigned int	t_to_sleep;
	unsigned int	nb_meal_max_eaten;
	pthread_mutex_t	mutex_on_write;
	unsigned int	philo_full;
	unsigned int	philo_dead;
} t_philo_times;

typedef struct	s_routine_arg
{
	int		i;
	t_philo	*philo_congregation;
} t_routine_arg;

unsigned int	ft_atoui_check(const char *str);
unsigned int	get_current_time_ms(void);

#endif
