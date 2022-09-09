/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:51:25 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/09 08:28:17 by vhaefeli         ###   ########.fr       */
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
	philosopher.time_alive = get_current_time_ms() + times.t_to_die;
	philosopher.nb_meal_eaten = 0;
	philosopher.times =	&times;
	return (philosopher);
}

void reinit_philo(t_philo *philo, int i)
{
	philo->time_alive = philo->times.t_to_die;
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
		times.nb_meal_eaten = ft_atoui_check(arg[5]);
	else
		times.nb_meal_eaten = 4294967295;
	return (times);
}

t_philo	*philo_congregation(int argc, char **argv)
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




}

t_routine_arg	*init_routine_arg(t_philo *philo_congregation, int nbr_of_philo)
{
	t_routine_arg	*routine_arguments;
	int				i;

	i = 0;
	while (i < nbr_of_philo)
	{
		routine_arguments->i = i;
		routine_arguments->philo_congregation = philo_congregation;
		i++;
	}
	return (routine_arguments);
}


int mails = 0;
pthread_mutex_t mutex;

void* routine() {
    for (int i = 0; i < 10000000; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char* argv[]) {
    pthread_t th[8];
    int i;
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < 8; i++) {
        if (pthread_create(th + i, NULL, &routine, &routine_arguments[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
        printf("Thread %d has started\n", i);
    }
    for (i = 0; i < 8; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            return 2;
        }
        printf("Thread %d has finished execution\n", i);
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return 0;
}
