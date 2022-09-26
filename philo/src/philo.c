/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:51:25 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/26 13:26:48 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_philo_times *times, unsigned int i)
{
	t_philo	*philosopher;

	philosopher = malloc(sizeof(t_philo));
	philosopher->philo_nb = i;
	if (i == times->nbr_of_philo - 1)
		philosopher->neighbour = 0;
	else
		philosopher->neighbour = i + 1;
	pthread_mutex_init(&philosopher->mutex_on_fork, NULL);
	philosopher->t_alive = times->start_time + times->t_to_die;
	philosopher->nb_meal_eaten = 0;
	philosopher->t = times;
	return (philosopher);
}

t_philo_times	*convert_times(int argc, char **argv)
{
	t_philo_times	*times;

	times = malloc(sizeof(t_philo_times));
	times->nbr_of_philo = ft_atoui_check(argv[1]);
	times->start_time = get_current_time_ms();
	times->t_to_die = ft_atoui_check(argv[2]);
	times->t_to_eat = ft_atoui_check(argv[3]);
	times->t_to_sleep = ft_atoui_check(argv[4]);
	if (argc == 6)
		times->nb_meal_max_eaten = ft_atoui_check(argv[5]);
	else
		times->nb_meal_max_eaten = 4294967295;
	pthread_mutex_init(&(times)->mutex_on_write, NULL);
	times->philo_full = 0;
	times->philo_dead = 0;
	return (times);
}

t_philo	**philo_congregation(int argc, char **argv)
{
	t_philo			**philo_congr;
	t_philo_times	*times;
	int				nbr_of_philo;
	int				i;

	i = 0;
	nbr_of_philo = ft_atoui_check(argv[1]);
	times = convert_times(argc, argv);
	philo_congr = malloc(sizeof(t_philo *) * nbr_of_philo);
	while (i < nbr_of_philo)
	{
		philo_congr[i] = init_philo(times, i);
		i++;
	}
	return (philo_congr);
}

t_r_arg	**init_routine_arg(t_philo **philo_congr)
{
	t_r_arg	**routine_arguments;
	int		i;
	int		n;

	i = 0;
	n = philo_congr[i]->t->nbr_of_philo;
	routine_arguments = malloc(sizeof(t_r_arg *) * n);
	while (i < n)
	{
		routine_arguments[i] = malloc(sizeof(t_r_arg));
		routine_arguments[i]->i = i;
		routine_arguments[i]->philo_congr = philo_congr;
		i++;
	}
	return (routine_arguments);
}

int	main(int argc, char **argv)
{
	pthread_t		*th;
	unsigned int	i;
	t_philo			**philo_congr;
	t_r_arg			**routine_arg;

	i = 0;
	if ((argc != 5 && argc != 6) || ft_atoui_check(argv[1]) < 1)
		return (error_arg());
	philo_congr = philo_congregation(argc, argv);
	if (check_args(philo_congr[0]->t))
		return (error_arg());
	routine_arg = init_routine_arg(philo_congr);
	th = malloc(sizeof(pthread_t) * philo_congr[0]->t->nbr_of_philo);
	while (i < philo_congr[0]->t->nbr_of_philo)
	{
		if (pthread_create(th + i, NULL, &eat_sleep_live, routine_arg[i]) != 0)
		{
			printf("Failed to create thread\n");
			return (1);
		}
		i++;
	}
	check_all_alive(philo_congr);
	philo_end(th, philo_congr, routine_arg);
	return (0);
}
