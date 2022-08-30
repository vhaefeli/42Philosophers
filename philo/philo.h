/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:44:25 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/08/26 11:28:48 by vhaefeli         ###   ########.fr       */
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

typedef struct s_list
{
	int				philo_nb;
	bool			fork_available;
	pthread_mutex_t mutex_on_fork;
	float			time_eating;
	float			time_sleeping;
	float			time_alive;
	int				nb_meal_eaten;
	struct s_list	next_philo;
} t_list;



#endif