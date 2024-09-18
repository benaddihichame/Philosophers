/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:46:27 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/18 18:11:19 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(t_forks) * table->human);
	if (!table->forks)
		return (0);
	while (i < table->human)
	{
		if (pthread_mutex_init(&table->forks[i].locked, NULL) != 0)
		{
			printf("Error: Failed to initialize mutex\n");
			return (0);
		}
		table->forks[i].num = i;
		i++;
	}
	if (pthread_mutex_init(&table->die_mutex, NULL) != 0)
	{
		printf("Error: Failed to initialize die_mutex\n");
		return (0);
	}
	return (1);
}

int	init_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->human);
	if (!table->philo)
		return (0);
	table->starting = get_curren_time();
	while (i < table->human)
	{
		table->died = 0;
		table->philo[i].id = i + 1;
		table->philo[i].meal_counter = 0;
		table->philo[i].time_from_last_meal = 0;
		table->philo[i].left_fork = &table->forks[i];
		table->philo[i].right_forks = &table->forks[(i + 1) % table->human];
		handle_mutex(&table->philo[i].meal_lock, INIT);
		table->philo[i].table = table;
		i++;
	}
	return (1);
}

int	test_param(t_table *arg)
{
	if (arg->human > 200 || arg->time_to_die < 0 || arg->time_to_eat < 0 \
	|| arg->time_to_sleep < 0)
	{
		printf("\033[1;31mERROR : ONE OR MUTLTIPLE ARG NOT GOOD\033[0m\n");
		return (0);
	}
	if (arg->time_to_die > INT_MAX || arg->time_to_eat > INT_MAX \
	|| arg->time_to_sleep > INT_MAX)
	{
		printf("\033[1;31mERROR : ARG IS ABOVE THE MAX VALUE\033[0m\n");
		return (0);
	}
	return (1);
}

int	parsing(t_table *arg, char **av)
{
	arg->human = mod_atol(av[1]);
	arg->time_to_die = mod_atol(av[2]);
	arg->time_to_eat = mod_atol(av[3]);
	arg->time_to_sleep = mod_atol(av[4]);
	if (av[5])
		arg->size_stomach = mod_atol(av[5]);
	else
		arg->size_stomach = -1;
	if (test_param(arg) == 0)
		return (0);
	if (init_forks(arg) == 0)
	{
		printf("Error : In the init of forks\n");
		return (0);
	}
	if (init_philo(arg) == 0)
	{
		printf("Error : In the init of philo\n");
		return (0);
	}
	return (1);
}
