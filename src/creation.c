/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:35:34 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/16 12:07:23 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_full(t_table *table, int i)
{
	handle_mutex(&table->die_mutex, LOCK);
	if (table->philo[i].meal_counter == table->size_stomach)
		i++;
	handle_mutex(&table->die_mutex, UNLOCK);
	if(i == table->human)
		return (1);
	return (0);
}
void	death(t_table *table, int i)
{
	handle_mutex(&table->philo[i].meal_lock, UNLOCK);
	who_is_doing(&table->philo[i], DIE);
	handle_mutex(&table->die_mutex, LOCK);
	table->died = 1;
	handle_mutex(&table->die_mutex, UNLOCK);
}
void	*undertaker(void *arg)
{
	int	i;

	t_table *table;
	table = (t_table *)arg;
	while (table->died == 0)
	{
		i =  0;
		while (i < table->human)
		{
			if(is_full(table, i))
				return (NULL);
			handle_mutex(&table->philo[i].meal_lock, LOCK);
			if (get_curren_time() - table->starting - table->philo[i].time_from_last_meal > table->time_to_die)
				death(table, i);
			handle_mutex(&table->philo[i].meal_lock, UNLOCK);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
void	*routine(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	while(1)
	{
		handle_mutex(&philo->table->die_mutex, LOCK);
		if (philo->table->died == 1)
		{
		handle_mutex(&philo->table->die_mutex, UNLOCK);
			break ;
		}
		handle_mutex(&philo->table->die_mutex, UNLOCK);
		if (philo->meal_counter == philo->table->size_stomach)
			break ;
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
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
	if (pthread_create(&table->death_thread, NULL, undertaker, table))
		return (0);
	pthread_join(table->death_thread, NULL);
	i = 0;
	while (i < table->human)
	{
		if (pthread_join(table->philo[i].philo_thread, NULL))
			return (0);
		i++;
	}
	return (1);
}