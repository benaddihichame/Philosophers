/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:39:44 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/17 22:52:25 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	who_is_doing(t_philo *philo, t_action code)
{
	long time;

	time = get_curren_time() - philo->table->starting;
	handle_mutex(&philo->table->die_mutex, LOCK);
	if (!philo->table->died)
	{
		if (code == EAT)
			printf("\033[38;5;214m%ld The Philo num %d is eating\033[0m\n",time, philo->id);
		if (code == SLEEP)
			printf("\033[38;5;129m%ld The Philo num %d is sleeping\033[0m\n",time, philo->id);
		if(code == THINK)
			printf("\033[34m%ld The Philo num %d is thinking\033[0m\n",time, philo->id);
		if (code == GRABLEFT)
			printf("\033[38;5;34m%ld The Philo num %d is taking left fork\033[0m\n",time, philo->id);
		if (code == GRABRIGHT)
			printf("\033[38;5;34m%ld The Philo num %d is taking right fork\033[0m\n",time, philo->id);
	}
	handle_mutex(&philo->table->die_mutex, UNLOCK);
    if (code == DIE)
	{
        printf("\033[38;5;34m%ldThe Philo num %d DIED\033[0m\n",time, philo->id);
	}
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