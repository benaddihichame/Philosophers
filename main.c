/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:55:27 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/08/26 11:58:48 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void*	fonctionnn()
{
	printf("johnpork is calling\n");
	sleep(3);
	printf("you decline\n");
}
int main()
{
	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1, NULL, &fonctionnn, NULL);
	pthread_create(&t2, NULL, &fonctionnn, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
