/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/16 17:30:23 by hbenaddi         ###   ########.fr       */
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

// Structure pour représenter les fourchettes
typedef struct s_forks
{
    pthread_mutex_t locked; // Mutex pour verrouiller l'accès à la fourchette
    int num;               // Indique si la fourchette est actuellement utilisée
}   t_forks;

// Structure pour représenter un philosophe
typedef struct s_philo
{
    int id;                     // Identifiant unique du philosophe
    long time_from_last_meal;   // Temps écoulé depuis le dernier repas
    long meal_counter;          // Nombre de repas pris
    int using_left;             // Indique si le philosophe utilise la fourchette gauche
    int using_right;            // Indique si le philosophe utilise la fourchette droite
    t_forks *left_fork;         // Pointeur vers la fourchette gauche
    t_forks *right_forks;       // Pointeur vers la fourchette droite
    pthread_t philo_thread;           // Thread représentant le philosophe
    pthread_mutex_t meal_lock;  // Mutex pour protéger l'accès aux données liées aux repas
    struct s_table *table;      // Pointeur vers la structure de la table
}   t_philo;

// Structure pour représenter la table et l'ensemble de la simulation
typedef struct s_table
{
    long human;                 // Nombre de philosophes
    long size_stomach;          // Nombre de repas que chaque philosophe doit manger
    long time_to_eat;           // Temps nécessaire pour manger
    long time_to_sleep;         // Temps de sommeil après avoir mangé
    long time_to_die;           // Temps maximum sans manger avant de mourir
    int end;                    // Indique si la simulation est terminée
    int died;                   // Indique si un philosophe est mort
    bool thread_ready;          // Indique si tous les threads sont prêts
    long starting;            // Temps de départ de la simulation
    pthread_mutex_t die_mutex;  // Mutex pour protéger l'accès à la variable 'died'
    pthread_t death_thread;     // Thread pour vérifier si un philosophe est mort
    t_philo *philo;             // Tableau des philosophes
    t_forks *forks;             // Tableau des fourchettes
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

typedef enum e_action
{
    DIE,
    EAT,
    THINK,
    SLEEP,
    GRABLEFT,
    GRABRIGHT,
}   t_action;

//                  ACTION
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	*routine(void *arg);
void	drop_fork(t_philo *philo);
void	take_fork(t_philo *philo);
void	*undertaker(void *arg);

//                  INITIALIZATION
int    init_thread(t_table *table);
int    parsing(t_table *arg, char **av);
char    *check_input(char *str);
void    handle_mutex(pthread_mutex_t *mutex, t_code code);

//              Time
int ft_usleep(size_t millisecondes, t_philo *philo);
long get_curren_time(void);

//                     Utils
void    free_stuff(t_table *table);
int ft_isdigit(char c);
long	mod_atol(char *s);
void	who_is_doing(t_philo *philo, t_action code);
void	free_all(t_table *table);
#endif