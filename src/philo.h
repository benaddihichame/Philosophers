/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/20 10:46:09 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_forks
{
	pthread_mutex_t	locked;
	int				num;

}					t_forks;

typedef struct s_philo
{
	int				id;
	long			time_from_last_meal;
	long			meal_counter;
	t_forks			*left_fork;
	t_forks			*right_forks;
	pthread_t		philo_thread;
	pthread_mutex_t	meal_lock;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	long			human;
	long			size_stomach;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	int				end;
	int				died;
	long			starting;
	pthread_mutex_t	die_mutex;
	pthread_t		death_thread;
	t_philo			*philo;
	t_forks			*forks;
}					t_table;

typedef enum e_code
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
}					t_code;

typedef enum e_action
{
	DIE,
	EAT,
	THINK,
	SLEEP,
	GRABLEFT,
	GRABRIGHT,
}					t_action;

void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);
void				*routine(void *arg);
void				drop_fork(t_philo *philo);
void				take_fork(t_philo *philo);
void				*undertaker(void *arg);

int					init_thread(t_table *table);
int					parsing(t_table *arg, char **av);
char				*check_input(char *str);
void				handle_mutex(pthread_mutex_t *mutex, t_code code);

int					ft_usleep(size_t millisecondes, t_philo *philo);
long				get_curren_time(void);

void				free_stuff(t_table *table);
int					ft_isdigit(char c);
long				mod_atol(char *s);
void				who_is_doing(t_philo *philo, t_action code);
void				free_all(t_table *table);
#endif
