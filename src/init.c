/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:46:27 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/10 15:58:32 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_forks(t_forks *forks, t_table *table)
{
    int i;

    i = 0;
    table->forks = malloc(sizeof(t_forks) * table->human);
    while (i < table->human)
    {
        forks[i].used = 0;
        handle_mutex(&forks[i].locked, INIT);
        i++;
    }
}
void    init_philo(t_philo *philo, t_forks *fork, t_table *table)
{
    int i;

    i = 0;
    table->philo = malloc(sizeof(t_philo) * table->human);
    while (i < table->human)
    {
        philo->id = i + 1;
        philo->meal_counter = 0;
        philo->time_from_last_meal = 0;
        philo->using_left = 0;
        philo->using_right = 0;
        philo->left_fork = &fork[i];
        philo->right_forks = &fork[(i + 1) % table->human];
        handle_mutex(&philo->meal_lock, INIT);
        philo[i].table = table;
        i++;
    }
}
int test_param(t_table *arg)
{
    if (arg->human > 200 || arg->time_to_die < 0 || arg->time_to_eat < 0 || arg->time_to_sleep < 0)
        return (0);
    if (arg->time_to_die > INT_MAX || arg->time_to_eat > INT_MAX || arg->time_to_sleep > INT_MAX)
        return (0);
    return (1);
}
int    parsing(t_table *arg, char **av)
{
    arg->human = mod_atol(av[1]);
    arg->time_to_die = mod_atol(av[2]) * 1000;
    arg->time_to_eat = mod_atol(av[3]) * 1000;
    arg->time_to_sleep = mod_atol(av[4]) * 1000;
    if (arg->time_to_die < 6000 || arg->time_to_eat < 6000 || arg->time_to_sleep < 6000)
        error_exit("\033[1;31mERROR : DON'T GO UNDER 60ms\033[0m\n");
    if (av[5])
        arg->size_stomach = mod_atol(av[5]);
    else
        arg->size_stomach = -1;
    if (test_param(arg) == 0)
        error_exit("\033[1;31mERROR : ONE OR MUTLTIPLE ARG NOT GOOD\033[0m\n");
    init_forks(arg->forks, arg);
    init_philo(arg->philo, arg->forks, arg);
    return (1);
}
// void    init_thread(t_table *table)
// {
//     int i;
    
//     i = 0;
//     while (i < table->human)
//     {
//         pthread_create(&table->philo[i], NULL, routine, &table->philo[i]);
//         i++;
//     }
// }