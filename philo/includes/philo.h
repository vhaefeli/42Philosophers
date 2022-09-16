/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:44:25 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/15 23:10:24 by vhaefeli         ###   ########.fr       */
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

typedef struct s_philo
{
	unsigned int	philo_nb;
	unsigned int	neighbour;
	pthread_mutex_t mutex_on_fork;
	unsigned int	t_alive;
	unsigned int	nb_meal_eaten;
	t_philo_times	*t;
} t_philo;

typedef struct	s_r_arg
{
	int		i;
	t_philo	**philo_congr;
} t_r_arg;

unsigned int	ft_atoui_check(const char *str);

unsigned int	get_current_time_ms(void);
unsigned int	chrono(int start_time);

int		check_death(t_philo_times *t, int phase);
void	pt_printf(char *msg, int moment, int philo_nb, t_philo_times *times);
int		philo_end(pthread_t *th, t_philo **philo_congr, t_r_arg *rout_arg);
int		error_arg(void);

int		philo_eat(t_philo **philo, int i);
int		philo_sleep(t_philo **philo, int i);
void	*eat_sleep_live_even(t_philo **philo, int i);
void	*eat_sleep_live_odd(t_philo **philo, int i);
void	*eat_sleep_live(void *argument);

t_philo 		*init_philo(t_philo_times *times, int i);
t_philo_times 	*convert_times(int argc, char **argv);
t_philo			**philo_congregation(int argc, char **argv);
t_r_arg			*init_routine_arg(t_philo **philo_congr);

#endif
