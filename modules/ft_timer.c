/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:38:44 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/18 12:47:46 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		sec;
	long long		usec;

	gettimeofday (&time, NULL);
	sec = time.tv_sec * 1e3;
	usec = time.tv_usec * 0.001;
	return (usec + sec);
}

void	msg(long long time,char *s, int key)
{
	printf("%lld		%d %s\n", time, key ,s);
}
void	no_tb(int e)
{
	msg(0, TAKE_FORKS, 1);
	my_sleep(e);
	printf("%d		1 died\n", e);
	msg(0, DIED, 1);
}
