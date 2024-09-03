/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_atol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:15:44 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/03 19:46:19 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    error_exit(const char *str)
{
    printf("%s", str);
    return (1);
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
        printf("Don't put negatif num");
        return (NULL);
    }
    if (ft_isdigit(*str) == 0)
    {  
        printf("You didnt put num wtf");
        return (NULL);
    }
    num = str;
    while (ft_isdigit(*str++))
        len++;
    if (len > 10)
    {  
        printf("You didnt good INT wtf");
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