/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/04 16:08:04 by hbenaddi         ###   ########.fr       */
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
    bool    thread_ready;
    pthread_mutex_t mtx_table;
    t_fork *forks;
    t_philo *philo;
}   t_table;

typedef enum e_code
{
    LOCK,
    UNLOCK,
    INIT,
    DETACH,
    DESTROY,
    CREATE,
}   t_code;

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
void    handle_mutex(pthread_mutex_t *mutex, t_code code);

//              mutex
void    setbool(pthread_mutex_t *mutex, bool *dest, bool value);
bool    getbool(pthread_mutex_t *mutex, bool *value);
long    getlong(pthread_mutex_t *mutex, long *value);
void    setlong(pthread_mutex_t *mutex, long *dest, long value);
#endif