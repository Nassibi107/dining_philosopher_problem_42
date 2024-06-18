/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:56:15 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/18 15:47:52 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	overf(t_time  n, t_time  o);
static int	rst(const char *s, t_time  rtn, int is_m);

int	ft_atoi(const char *str)
{
	int					is_m;
	t_time		res;

	is_m = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_m = is_m * -1;
		str++;
	}
	return (rst(str,res, is_m) * is_m);
}

static int	rst(const char *s, t_time  rtn, int is_m)
{
	t_time	save;

	while (*s >= '0' && *s <= '9')
	{
		save = rtn;
		rtn = rtn * 10 + (*s - '0');
		if (overf(rtn, save) == 0)
			s++;
		else if (overf(rtn, save) == 1)
		{
			if (is_m == -1)
				return (0);
			return (-1);
		}
	}
	return (rtn);
}
static int	overf(t_time  n, t_time  o)
{
	if ((n / 10) == o)
		return (0);
	return (1);
}
