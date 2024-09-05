/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:57:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/04 14:45:58 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    setbool(pthread_mutex_t *mutex, bool *dest, bool value)
{
    handle_mutex(&mutex, LOCK);
    *dest = value;
    handle_mutex(&mutex, UNLOCK);
}
bool    getbool(pthread_mutex_t *mutex, bool *value)
{
    bool result;

    handle_mutex(&mutex, LOCK);
    result = *value;
    handle_mutex(&mutex, UNLOCK);
    return (result);
}
long    getlong(pthread_mutex_t *mutex, long *value)
{
    long result;

    handle_mutex(&mutex, LOCK);
    result = *value;
    handle_mutex(&mutex, UNLOCK);
    return (result);
}
void    setlong(pthread_mutex_t *mutex, long *dest, long value)
{
    handle_mutex(&mutex, LOCK);
    *dest = value;
    handle_mutex(&mutex, UNLOCK);
}