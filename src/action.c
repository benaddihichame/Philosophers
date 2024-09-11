/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:41:28 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/11 21:32:57 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork()
{
	
}
void	drop_fork()
{

}
void	eating(t_philo *philo)
{
	take_fork();
	who_is_doing(philo, EAT);
	handle_mutex(&philo->meal_lock,LOCK);
	philo->time_from_last_meal = get_curren_time() - philo->table->starting;
	handle_mutex(&philo->meal_lock, UNLOCK);
	ft_usleep(philo->table->time_to_eat, philo);
	handle_mutex(&philo->table->die_mutex, LOCK);
	philo->meal_counter++;
	handle_mutex(&philo->table->die_mutex, UNLOCK);
	drop_forks();

}
void	sleeping(t_philo *philo)
{
	who_is_doing(philo, SLEEP);
	ft_usleep(philo->table->time_to_sleep, philo);
}
void	thinking(t_philo *philo)
{
	who_is_doing(philo, THINK);
	ft_usleep(1, philo);
}