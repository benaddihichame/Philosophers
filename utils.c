/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:15:44 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/08/26 18:59:31 by hbenaddi         ###   ########.fr       */
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
        printf("Don't put negatif num");
        exit(0) ;
    }
    if (ft_isdigit(*str) == 0)
    {  
        printf("You didnt put num wtf");
        exit(0) ;
    }
    num = str;
    while (ft_isdigit(*str++))
        len++;
    if (len > 10)
    {  
        printf("You didnt good INT wtf");
        exit(0) ;
    }
    return (num);
}
long	mod_atol(char *s)
{
	long	res;
	int		sign;

    s = check_input(s);
	res = 0;
	while (*s >= '0' && *s <= '9')
    {
        res = res * 10 + (*s - '0');
        s++;
    }
    return (res);
}

int main()
{
   char *s = "-132";
	long result = mod_atol(s);
	printf("%ld\n", result);
}