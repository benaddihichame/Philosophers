/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:39:44 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/05 10:40:43 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    wait_threads(t_table *table)
{
    while (!getbool(&table->mtx_table, &table->thread_ready))
    {
        usleep(100); // Ajout d'un temps d'attente pour éviter une boucle infinie
    }
}
void    handle_mutex(pthread_mutex_t *mutex, t_code code)
{
    if (code == LOCK)
        pthread_mutex_lock(mutex);
    else if (code == UNLOCK)
        pthread_mutex_unlock(mutex);
    else if (code == INIT)
        pthread_mutex_init(mutex, NULL);
    else if (code == DESTROY)
        pthread_mutex_destroy(mutex);
    else
        error_exit("ERROR : code not good");
}