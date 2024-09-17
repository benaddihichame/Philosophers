/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:41:28 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/17 15:33:32 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->left_fork->num < philo->right_forks->num)
	{
		if (philo->table->human == 1)
		{
			usleep(philo->table->time_to_die * 2000);
			return ;
		}
		handle_mutex(&philo->left_fork->locked, LOCK);
		who_is_doing(philo, GRABLEFT);
		handle_mutex(&philo->right_forks->locked, LOCK);
		who_is_doing(philo, GRABRIGHT);
	}
	else
	{
		handle_mutex(&philo->right_forks->locked, LOCK);
		who_is_doing(philo, GRABRIGHT);
		if (philo->table->human == 1)
		{
			usleep(philo->table->time_to_die * 2000);
			return ;
		}
		handle_mutex(&philo->left_fork->locked, LOCK);
		who_is_doing(philo, GRABLEFT);
	}
}
void	drop_fork(t_philo *philo)
{
	if (philo->left_fork->num < philo->right_forks->num)
	{
		handle_mutex(&philo->left_fork->locked, UNLOCK);
		handle_mutex(&philo->right_forks->locked, UNLOCK);
	}
	else
	{
		handle_mutex(&philo->right_forks->locked, UNLOCK);
		handle_mutex(&philo->left_fork->locked, UNLOCK);
	}
}
void	eating(t_philo *philo)
{
	take_fork(philo);
	who_is_doing(philo, EAT);
	handle_mutex(&philo->meal_lock,LOCK);
	philo->time_from_last_meal = get_curren_time() - philo->table->starting;
	handle_mutex(&philo->meal_lock, UNLOCK);
	ft_usleep(philo->table->time_to_eat, philo);
	handle_mutex(&philo->table->die_mutex, LOCK);
	philo->meal_counter++;
	handle_mutex(&philo->table->die_mutex, UNLOCK);
	drop_fork(philo);

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