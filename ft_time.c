/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:24:56 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/10 19:33:02 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


long	ft_time(void)
{
	struct timeval	mytime;

	if (gettimeofday(&mytime, NULL))
		return (0);
	return ((mytime.tv_sec * (u_int64_t)1000) + (mytime.tv_usec / 1000));
}

void	sleeper(long tel)
{
	int			wait;
	long	time;

	wait = 5;
	while (1337)
	{
		time = ft_time() ;
		if (tel <= time + wait)
		{
			while (tel > time)
				time = ft_time();
			break ;
		}
		else
			usleep(1000 * (tel - time - wait));
	}
}

void	ft_usleep(long tts)
{
	long	start;

	start = ft_time();
	while ((ft_time() - start) < tts)
		usleep(500);
}


