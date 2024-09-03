/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:27 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/03 21:07:02 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int ac, char **av)
{
    t_table args;

    if(ac == 5 || ac == 6)
    {
        if (parsing(&args, av) == 0)
            return (error_exit("Error : In The Parsing\n"));
        if (data_init(&args) == 1)   
            return (error_exit("Error : In The Initialization"));
        
    }
    else
        printf("wrong number of arg");
    return 0;
}