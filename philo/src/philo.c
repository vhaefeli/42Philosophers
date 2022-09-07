/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:51:25 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/09/07 15:19:49 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"



t_philo init_philo(t_philo_times times, int i)
{
	t_philo	philosopher;

	philosopher.philo_nb = i;
	pthread_mutex_init(&philosopher.mutex_on_fork, NULL);
	philosopher.time_alive = get_current_time_ms() + times.time_to_die;
	philosopher.nb_meal_eaten = 0;
	return (philosopher);
}

t_philo reinit_philo(t_philo_times times, int i)
{
	t_philo	philosopher;

	philosopher.philo_nb = i;
	philosopher.time_eating = times.time_to_eat;
	philosopher.time_sleeping = times.time_to_sleep;
	philosopher.time_alive = times.time_to_die;
	return (philosopher);
}



t_philo_times convert_times(int argc, char **argv)
{
	t_philo_times	times;

	times.start_time = get_current_time_ms();
	times.time_to_die = ft_atoui_check(argv[2]);
	times.time_to_eat = ft_atoui_check(argv[3]);
	times.time_to_sleep = ft_atoui_check(argv[4]);
	if (argc == 6)
		times.nb_meal_eaten = ft_atoui_check(arg[5]);
	else
		times.nb_meal_eaten = 4294967295;
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
        if (pthread_create(th + i, NULL, &routine, NULL) != 0) {
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
