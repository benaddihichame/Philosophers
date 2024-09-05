/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_la_dalle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:08:28 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/04 16:34:20 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_philo();
	return (NULL);
}
void	the_dinner(t_table *table)
{
	int i;

	i = 0;
	if (table->size_stomach == 0)
		return ;
	else if (table->human == 1)
		;//todo 
	else
	{

		while (i < table->human)
		{
			pthread_create(&table->philo[i], NULL, routine, &table->philo[i]);
			i++;
		}
		setbool(&table->mtx_table, &table->thread_ready, true);
	}	
}