/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:46:27 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/02 19:53:18 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *s)
{
    int i = 0;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
char    *check_input(char *str)
{
    int len;
    char    *num;

    len = 0;
    while ((*str >= 9 && *str <= 13 )|| *str == 32)
        str++;
    if (*str == '+')
        str++;
    else if (*str == '-')
    {
        printf("Error :Don't put negatif num");
        return (NULL);
    }
    if (ft_isdigit(*str) == 0)
    {  
        printf("Error : You didnt put num");
        return (NULL);
    }
    num = str;
    while (ft_isdigit(*str++))
        len++;
    if (len > 10)
    {  
        printf("Error : You didnt good INT");
        return (NULL);
    }
    return (num);
}
long	mod_atol(char *s)
{
	long	res;

    s = check_input(s);
	res = 0;
	while (*s >= '0' && *s <= '9')
    {
        res = res * 10 + (*s - '0');
        s++;
    }
    return (res);
}
int    data_init(t_table *args)
{
    int i;

    i = 0;
    args->end = false; 
    args->philo = malloc(sizeof(t_philo) * args->human);
    args->forks = malloc(sizeof(pthread_mutex_t) * args->human);
    if (!args->philo || !args->forks)
    {
        printf("Error : malloc");
        return (1);
    }
    while (i < args->human)
    {
        args->forks[i].fork_id = i;
        //pthread_mutex_init(&args->forks[i].fork, NULL);
        args->philo[i].id = i + 1;
        args->philo[i].left_fork = &args->forks[i];
        args->philo[i].right_fork = &args->forks[(i + 1) % args->human];
        args->philo[i].table = args;
        i++;
    }
    return (0);
}
void    parsing(t_table *arg, char **av)
{
    arg->human = mod_atol(av[1]);
    arg->time_to_die = mod_atol(av[2]) * 1000;
    arg->time_to_eat = mod_atol(av[3]) * 1000;
    arg->time_to_sleep = mod_atol(av[4]) * 1000;
    if (arg->time_to_die < 6000 || arg->time_to_eat < 6000 || arg->time_to_sleep < 6000)
    {
        printf("dont go down 60ms");
        exit(0) ;
    }
    if (av[5])
        arg->size_stomach = mod_atol(av[5]);
    else
        arg->size_stomach = -1;
}

void    *routine(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    printf("Philo number %d is eating\n", philo->id);
    return NULL;
}
int main(int ac, char **av)
{
    t_table table;

    int i = 0;
    if (ac == 5 || ac == 6)
    {
        parsing(&table, av);
        if (data_init(&table) != 0)
            return (1);
        
        while (i < table.human)
        {
            pthread_create(&table.philo[i].philo_id, NULL, &routine, &table.philo[i]);
            i++;
        }
        i = 0;
        while(i < table.human)
        {
            pthread_join(table.philo[i].philo_id, NULL);
            i++;
        }
    }
    else
        printf("Wrong number of argument");
    
    // Free resources and destroy mutexes
    for (i = 0; i < table.human; i++)
    {
        pthread_mutex_destroy(&table.forks[i].fork);
    }
    free(table.philo);
    free(table.forks);

    return 0;
}