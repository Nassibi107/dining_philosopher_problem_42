/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:40:36 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/16 14:15:57 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

int	ins_range(long n)
{
	if (n <= 0 || n >= 2147483647)
		return (0);
	return (1);
}

int	is_digit(char *s)
{
	int	i;
	int	size;

	size = ft_strlen(s);
	i = 0x0;
	while (i < size)
	{
		if (!(s[i] >= 48 && s[i] <= 57))
			return (0x0);
		i++;
	}
	return (0x1);
}

int	ft_isnumber(char *av)
{
	if (!is_digit(av) || (!ins_range(ft_atoi(av))))
		return (1);
	return (0);
}
int	parcer(char **av , int ac)
{
	int	i;

	i = 1;
	while ( i < ac  - 1)
		{
			if (ft_isnumber(av[i]) == 1)
			{
				printf("parcer erorr");
					return (1);
			}
		i++;
	}
	return (0);
}
