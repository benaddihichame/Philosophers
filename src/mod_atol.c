/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_atol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:15:44 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/18 18:17:56 by hbenaddi         ###   ########.fr       */
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

char	*check_input(char *str)
{
	char	*num;
	int		len;

	len = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		return (NULL);
	while (str[len])
	{
		if (ft_isdigit(str[len]) == 0)
			return (NULL);
		len++;
	}
	len = 0;
	num = str;
	while (ft_isdigit(*str++))
		len++;
	if (len > 10)
		return (NULL);
	return (num);
}

long	mod_atol(char *s)
{
	long	res;

	s = check_input(s);
	if (s == NULL)
	{
		printf("\033[1;31mERROR from ATOL\033[0m\n");
		return (-1);
	}
	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res);
}
