/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:51:25 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/14 23:15:02 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"



t_philo init_philo(t_philo_times times, int i)
{
	t_philo	philosopher;

	philosopher.philo_nb = i;
	if (i == 0)
		philosopher.neighbour = times.nbr_of_philo - 1;
	else
		philosopher.neighbour = i - 1;
	pthread_mutex_init(&philosopher.mutex_on_fork, NULL);
	philosopher.t_alive = get_current_time_ms() + times.t_to_die;
	philosopher.nb_meal_eaten = 0;
	philosopher.t =	&times;
	return (philosopher);
}

t_philo_times convert_times(int argc, char **argv)
{
	t_philo_times	times;

	times.nbr_of_philo = ft_atoui_check(argv[1]);
	times.start_time = get_current_time_ms();
	times.t_to_die = ft_atoui_check(argv[2]);
	times.t_to_eat = ft_atoui_check(argv[3]);
	times.t_to_sleep = ft_atoui_check(argv[4]);
	if (argc == 6)
		times.nb_meal_max_eaten = ft_atoui_check(argv[5]);
	else
		times.nb_meal_max_eaten = 4294967295;
	pthread_mutex_init(&times.mutex_on_write, NULL);
	times.philo_full = 0;
	times.philo_dead = 0;
	return (times);
}

t_philo	**philo_congregation(int argc, char **argv)
{
	t_philo 		*philo_congr;
	t_philo_times	times;
	int				nbr_of_philo;
	int				i;

	i = 0;
	nbr_of_philo = ft_atoui_check(argv[1]);
	times = convert_times(argc, argv);
	philo_congr = malloc(sizeof(t_philo) * nbr_of_philo);
	while (i < nbr_of_philo)
	{
		philo_congr[i] = init_philo(times, i);
		i++;
	}
	return (&philo_congr);
}

t_routine_arg	*init_routine_arg(t_philo **philo_congregation)
{
	t_routine_arg	*routine_arguments;
	int				i;
	int				n;

	i = 0;
	n = philo_congregation[i]->t->nbr_of_philo;
	while (i < n)
	{
		routine_arguments->i = i;
		routine_arguments->philo_congregation = philo_congregation;
		i++;
	}
	return (routine_arguments);
}

int main(int argc, char* argv[]) 
{
	pthread_t		th[ft_atoui_check(argv[1])];
	int				i;
	int				n;
	t_philo			**philo_congr;
	t_routine_arg	*routine_arg;

	i = 0;
	philo_congr = philo_congregation(argc, argv);
	n = philo_congr[i]->t->nbr_of_philo;
	routine_arg = init_routine_arg(philo_congr)
	while (i < n)
	{
		if (pthread_create(th + i, NULL, &eat_sleep_live, &routine_arguments[i]) != 0)
		{
			printf("Failed to create thread");
			return 1;
		}
		i++;
	}
	ft_philo_end(&th, philo_congr);
	return 0;
}