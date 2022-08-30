/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:51:25 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/08/27 01:14:20 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"



t_list	*init_philo(char **argv)

t_list	*philo_congregation(char **argv)
{
	t_list	*first_philo;
	t_list	*new_philo;
	t_list	*next_philo;
	int		nbr_of_philo;

	nbr_of_philo = 
	first_philo = init_philo(argv);
	i = ft_pipe_split(cmdline, first_cmd, i);
	if (i >= 0 && cmdline[i] != 0)
		new_cmd1 = first_cmd;
	while (i >= 0 && cmdline[i] != 0)
	{
		printf("listcmd i:%d\n", i);
		new_cmd2 = ft_ininewlst_el();
		new_cmd2->previous = new_cmd1;
		new_cmd1->next = new_cmd2;
		i = ft_pipe_split(cmdline, new_cmd2, i);
		printf("listcmd i:%d\n", i);
		new_cmd1 = new_cmd2;
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