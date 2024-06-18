/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:56:15 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/18 12:57:02 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


static int	overf(long long int n, long long int o)
{
	if ((n / 10) == o)
		return (0);
	return (1);
}

static int	rst(long long int res, int sign, const char *str)
{
	long long int	old_res;

	while (*str >= '0' && *str <= '9')
	{
		old_res = res;
		res = res * 10 + (*str - '0');
		if (overf(res, old_res) == 0)
			str++;
		else if (overf(res, old_res) == 1)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	long long int		res;
	int					sign;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	return (rst(res, sign, str) * sign);
}
