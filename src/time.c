/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:52:25 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/16 11:47:23 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_curren_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t millisecondes, t_philo *philo)
{
	int		health;
	size_t	start;

	start = get_curren_time();
	while (get_curren_time() - start < millisecondes)
	{
		handle_mutex(&philo->table->die_mutex, LOCK);
		health = philo->table->died;
		handle_mutex(&philo->table->die_mutex, UNLOCK);
		if (health == 1)
			break ;
		usleep(500);
	}
	return (0);
}
