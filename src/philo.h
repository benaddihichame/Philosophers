/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/03 20:02:34 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>
#include <stdbool.h>

typedef struct s_table t_table;

typedef struct s_fork
{
    pthread_mutex_t fork;
    int fork_id;
}   t_fork;

typedef struct s_philo
{
    int id;
    long meal_counter;
    long    time_from_last_meal;
    bool    end;
    t_fork *left_fork;
    t_fork *right_fork;
    t_table *table;
}               t_philo;

typedef struct s_table
{
    long    human;
    long    size_stomach;  
    long    time_to_eat;
    long    time_to_die;
    long    time_to_sleep;
    t_fork *forks;
    t_philo *philo;
}   t_table;

int data_init(t_table *args);
int parsing(t_table *arg, char **av);
int ft_usleep(size_t millisecondes);
//                     Utils
char    *check_input(char *str);
int ft_strlen(char *s);
int    error_exit(const char *str);
int ft_isdigit(char c);
int error_exit(const char *str);
long	mod_atol(char *s);
#endif