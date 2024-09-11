/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:35:34 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/11 21:22:28 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	while(1)
	{
		handle_mutex(&philo->table->died, LOCK);
		if (philo->table->died)
		{
			handle_mutex(&philo->table->die_mutex, UNLOCK);
			break ;
		}
		

	}
	return ;
}

int	heart(t_table *table)
{
	
}
int		init_mutex()
{
	
}
int    init_thread(t_table *table)
{
    int i;   
    i = 0;
    while (i < table->human)
    {
        if (pthread_create(&table->philo[i].philo_thread, NULL, routine, &table->philo[i]))
			return (0);
        usleep(100);
		i++;
    }
	while(i < table->human)
	{
		if(pthread_join(table->philo[i].philo_thread, NULL))
			return (0);
		i++;
	}
	return (1);
}