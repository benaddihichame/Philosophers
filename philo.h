/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/08/29 17:32:30 by hbenaddi         ###   ########.fr       */
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
    pthread_mutex_t *fork;
    pthread_mutex_t mutex;
    pthread_t *philo;
    pthread_t thread; // Ajout d'un membre pour le thread
    int id_fork;
    long    human;
    long    time_to_eat;
    long    time_to_die;
    long    time_to_sleep;
    long    size_stomach;
    bool    end;
}               t_philo;

//                     Utils
char    *check_input(char *str);
int ft_strlen(char *s);
int	ft_isdigit(char c);
long	mod_atol(char *s);

#endif