/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:46:27 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/08/29 17:39:21 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// is int
// not > int max
// timetamps > 60ms

void    data_init(t_philo *args)
{
    int i;

    i = 0;
    args->end = false; 
    args->philo = malloc(sizeof(t_philo) * args->human);
    args->fork = malloc(sizeof(pthread_mutex_t) * args->human);
    if (!args->philo || !args->fork)
    {
        printf("Erreur malloc");
        return ;
    }
    while (i < args->human)
    {
        pthread_mutex_init(&args->fork[i], NULL);
        i++;
    }
}
void    parsing(t_philo *arg, char **av)
{
    arg->human = mod_atol(av[1]);
    arg->time_to_die = mod_atol(av[2]) * 1000;
    arg->time_to_eat = mod_atol(av[3]) * 1000;
    arg->time_to_sleep = mod_atol(av[4]) * 1000;
    if (arg->time_to_die < 6000 || arg->time_to_eat < 6000 || arg->time_to_sleep < 6000)
    {
        prinf("dont go down 60ms");
        return ;
    }
    if (av[5])
        arg->size_stomach = mod_atol(av[5]);
    else
        arg->size_stomach = -1;
}
