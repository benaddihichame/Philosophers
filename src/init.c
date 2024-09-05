/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:46:27 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/04 10:42:46 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    parsing(t_table *arg, char **av)
{
    arg->human = mod_atol(av[1]);
    arg->time_to_die = mod_atol(av[2]) * 1000;
    arg->time_to_eat = mod_atol(av[3]) * 1000;
    arg->time_to_sleep = mod_atol(av[4]) * 1000;
    if (arg->time_to_die < 6000 || arg->time_to_eat < 6000 || arg->time_to_sleep < 6000)
    {
        printf("dont go under 60ms");
        return(0) ;
    }
    if(arg->human > 200)
    {
        printf("ERROR : Don't use more then 200 philo\n");
        return(0);
    }
    if (av[5])
        arg->size_stomach = mod_atol(av[5]);
    else
        arg->size_stomach = -1;
    return (1);
}
void    give_forks(t_philo *philo, t_table *forks, int position)
{
    int philo_num;

    philo->left_fork = &forks[position];
    philo->right_fork = &forks[(position + 1) % philo_num];
    if (philo->id % 2 == 0)
    {
        philo_num = philo->table->human;
        philo->right_fork = &forks[position];
        philo->left_fork = &forks[(position + 1) % philo_num];
    }
}

void    init_philo(t_table *table)
{
    int i;
    t_philo *philo;

    i = 0;
    while (i < table->human)
    {
        philo = table->philo + i;
        philo->id = i;
        philo->meal_counter = 0;
        philo->end = false;
        philo->table = table;
        give_forks(philo, table->forks, i);
        i++;
    }
}
int    data_init(t_table *args)
{
    int i;

    i = 0;
    args->philo = malloc(sizeof(t_philo) * args->human);
    args->forks = malloc(sizeof(t_fork) * args->human);
    pthread_mutex_init(&args->mtx_table, NULL);
    if (!args->philo || !args->forks)
        return (error_exit("Error : Malloc"));
    while (i < args->human)
    {
        args->forks[i].fork_id = i;
        pthread_mutex_init(&args->forks[i].fork, NULL);
        i++;
    }
    init_philo(args);
    return (0);
}