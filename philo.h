/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/08/26 18:19:27 by hbenaddi         ###   ########.fr       */
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

typedef struct s_philo
{
    int fork;
    pthread_t *philo;
    pthread_t *t1;
    pthread_mutex_t mutex;

}   t_philo;

typedef struct s_args
{
    long    human;
    long    time_to_eat;
    long    time_to_die;
    long    time_to_sleep;
    long    size_stomach;
    bool    end;
}               t_args;

//                     Utils
char    *check_input(char *str);
int ft_strlen(char *s);
int	ft_isdigit(char c);
#endif