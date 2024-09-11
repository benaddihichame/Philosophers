/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_atol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:15:44 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/11 13:45:14 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
        printf("\033[1;31mERROR: DON'T PUT NEGATIVE NUMBERS\033[0m\n");
        return (NULL);
    }
    while(str[len])
    {
        if (ft_isdigit(str[len]) == 0)
        {
        printf("\033[1;31mERROR: YOU DIDN'T PUT A DIGIT\033[0m\n");
        return (NULL);
        }
        len++;
    }
    len = 0;
    num = str;
    while (ft_isdigit(*str++))
        len++;
    if (len > 10)
    {  
        printf("\033[1;31mERROR: YOU DIDN'T PROVIDE A VALID INTEGER\033[0m\n");
        return (NULL);
    }
    return (num);
}
long	mod_atol(char *s)
{
	long	res;

    	s = check_input(s);
    	if (s == NULL)
        {
        	printf("\033[1;31mERROR : ATOL\033[0m\n");
            return 0;
        }
        res = 0;
	while (*s >= '0' && *s <= '9')
    	{
    		res = res * 10 + (*s - '0');
		s++;
	}
	return (res);
}
