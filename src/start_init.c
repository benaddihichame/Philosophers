/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:46:27 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/16 13:06:55 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_forks(t_table *table)
{
    int i;

    if (table == NULL || table->human <= 0)
    {
        printf("Error: Invalid table or number of philosophers\n");
        return (0);
    }

    table->forks = malloc(sizeof(t_forks) * table->human);
    if (!table->forks)
    {
        printf("Error: Memory allocation failed for forks\n");
        return (0);
    }

    i = 0;
    while (i < table->human)
    {
        table->forks[i].num = i;
        if (pthread_mutex_init(&table->forks[i].locked, NULL) != 0)
        {
            printf("Error: Mutex initialization failed\n");
            // Free already allocated memory
            while (--i >= 0)
                pthread_mutex_destroy(&table->forks[i].locked);
            free(table->forks);
            return (0);
        }
        i++;
    }

    if (pthread_mutex_init(&table->die_mutex, NULL) != 0)
    {
        printf("Error: Die mutex initialization failed\n");
        // Free all allocated resources
        for (i = 0; i < table->human; i++)
            pthread_mutex_destroy(&table->forks[i].locked);
        free(table->forks);
        return (0);
    }

    return (1);
}
// int    init_forks(t_forks *forks, t_table *table)
// {
//     int i;

//     i = 0;
//     table->forks = malloc(sizeof(t_forks) * table->human);
//     if (!table->forks)
//         return (0);
//     while (i < table->human)
//     {
//         forks[i].num = i;
//         handle_mutex(&forks[i].locked, INIT);
//         i++;
//     }
//     handle_mutex(&table->die_mutex, INIT);
//     return (1);
// }
int    init_philo(t_philo *philo, t_forks *fork, t_table *table)
{
    int i;

    i = 0;
    table->philo = malloc(sizeof(t_philo) * table->human);
    if (!table->philo)
        return (0);
    table->starting = get_curren_time();
    while (i < table->human)
    {
        philo->id = i + 1;
        philo->meal_counter = 0;
        philo->time_from_last_meal = 0;
        philo->using_left = 0;
        table->died = 0;
        philo->using_right = 0;
        philo->left_fork = &fork[i];
        philo->right_forks = &fork[(i + 1) % table->human];
        handle_mutex(&philo->meal_lock, INIT);
        philo[i].table = table;
        i++;
    }
    return (1);
}
int test_param(t_table *arg)
{
    if (arg->human > 200 || arg->time_to_die < 0 || arg->time_to_eat < 0 || arg->time_to_sleep < 0)
    {
        printf("\033[1;31mERROR : ONE OR MUTLTIPLE ARG NOT GOOD\033[0m\n");
        return (0);
    }
    if (arg->time_to_die > INT_MAX || arg->time_to_eat > INT_MAX || arg->time_to_sleep > INT_MAX)
    {
        printf("\033[1;31mERROR : ONE OR MUTLTIPLE ARG IS ABOVE THE MAX VALUE\033[0m\n");
        return (0);
    }
    return (1);
}
int    parsing(t_table *arg, char **av)
{
    arg->human = mod_atol(av[1]);
    arg->time_to_die = mod_atol(av[2]) * 1000;
    arg->time_to_eat = mod_atol(av[3]) * 1000;
    arg->time_to_sleep = mod_atol(av[4]) * 1000;
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
    if (init_philo(arg->philo, arg->forks, arg) == 0)
    {
        printf("Error : In the init of philo\n");
        return (0);
    }
    return (1);
}