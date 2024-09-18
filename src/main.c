/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:27 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/17 21:56:10 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	args;

	if (ac < 5 || ac > 6)
	{
		printf("\033[1;31mERROR : WRONG NUMBER OF ARGUMENT\033[0m\n");
		return (1);
	}
	if (parsing(&args, av) == 0)
		return (1);
	if (init_thread(&args) == 0)
	{
		free_all(&args);
		return (1);
	}
	free_all(&args);
	pthread_exit(NULL);
	return (0);
}
