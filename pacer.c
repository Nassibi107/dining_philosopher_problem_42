/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:49:42 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/04 19:01:22 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	size_t	rst;

	s = 1;
	rst = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			s *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		rst *= 10;
		rst += str[i] - '0';
		i++;
	}
	return (rst * s);
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

	i = 0x0;
	while (s[i])
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
