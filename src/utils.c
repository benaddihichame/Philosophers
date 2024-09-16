/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:39:44 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/16 12:13:48 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	who_is_doing(t_philo *philo, t_action code)
{
	if (code == EAT)
		printf("\033[38;5;214mThe Philo num %d is eating\033[0m\n", philo->id);
	if (code == SLEEP)
		printf("\033[38;5;129mThe Philo num %d is sleeping\033[0m\n", philo->id);
	if(code == THINK)
		printf("\033[38;5;34mThe Philo num %d is sleeping\033[0m\n", philo->id);
    if (code == GRABLEFT)
    	printf("\033[38;5;34mThe Philo num %d is tacking left fork\033[0m\n", philo->id);
    if (code == GRABRIGHT)
    	printf("\033[38;5;34mThe Philo num %d is tacking right fork\033[0m\n", philo->id);
    if (code == DIE)
        printf("\033[38;5;34mThe Philo num %d DIED\033[0m\n", philo->id);
}
void    handle_mutex(pthread_mutex_t *mutex, t_code code)
{
    if (code == LOCK)
        pthread_mutex_lock(mutex);
    else if (code == UNLOCK)
        pthread_mutex_unlock(mutex);
    else if (code == INIT)
        pthread_mutex_init(mutex, NULL);
    else if (code == DESTROY)
        pthread_mutex_destroy(mutex);
    else
        {
            printf("Error code\n");
            return ;
        }
}
void	free_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->human)
	{
		pthread_mutex_destroy(&table->philo[i].meal_lock);
		pthread_mutex_destroy(&table->forks[i].locked);
		i++;
	}
	i = 0;
	pthread_mutex_destroy(&table->die_mutex);
	free(table->philo);
	free(table->forks);
}