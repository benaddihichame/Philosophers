/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:27 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/08/31 18:14:10 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void *threadFunction(void *arg) {
    printf("This is the detached thread.\n");
    // Simulate some work in the thread
    sleep(2);
    printf("The detached thread is done.\n");
    // No need to explicitly call pthread_exit() in a detached thread
    return NULL;
}

int main(int ac, char **av)
{
    if(ac == 5 || ac == 6)
    {

    }
    else
        
    return 0;
}