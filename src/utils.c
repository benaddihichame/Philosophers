/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:39:44 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/11 20:36:02 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	who_is_doing(t_philo *philo, t_code code)
{
	if (code == EAT)
	{
		printf("\033[38;5;214mThe Philo num %d is eating\033[0m\n", philo->id);
	}
	if(code == SLEEP)
	{
		printf("\033[38;5;129mThe Philo num %d is sleeping\033[0m\n", philo->id);
	}
	if(code == THINK)
	{
		printf("\033[38;5;34mThe Philo num %d is sleeping\033[0m\n", philo->id);
	}
}
int    error_exit(const char *str)
{
    printf("%s", str);
    return(1);
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
        error_exit("ERROR : code not good");
}
void    free_stuff(t_table *table)
{
    int i = 0;

    while (i < table->human)
    {
        free(table->philo);
        free(table->forks);
        i++;
    }
}