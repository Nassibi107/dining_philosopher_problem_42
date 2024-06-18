/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:38:26 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/18 15:38:11 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo			*data;
	t_tools			s;

	data = (t_philo *)arg;
	s.t0 = get_time();
	s.t1 = 0;
	if (data->ts_eats < 0)
		s.ii = -2;
	else
		s.ii = 0;
	if (data->key % 2 == 0)
		usleep(1000);
	while (s.ii < data->ts_eats)
	{
		data->t = s_rte(s.t0 , data);
		data->t = wait_rte(s.t0 , data);
		ft_sheft(data->t, s.t1, data);
		if (data->fa->diedd == DEATH)
			return (0);
		if (data->ts_eats == -1)
			continue ;
		else
			s.ii++;
	}
	return (0);
}
void	ft_eat(int n, t_time time, t_philo *data)
{
	muts(mut_lock ,data->print);
	if (data->fa->diedd == 1)
		msg(time, EAT, n);
	muts(mut_unlock ,data->print);
}

void	ft_sleep(int n, t_time time, t_philo *data)
{
	muts(mut_lock ,data->print);
	if (data->fa->diedd == 1)
		msg(time, SLEEP, n);
	muts(mut_unlock ,data->print);
}

void	ft_think(int n, t_time time, t_philo *data)
{
		muts(mut_lock ,data->print);
	if (data->fa->diedd == 1)
		msg(time, THINK, n);
	muts(mut_unlock ,data->print);
}

void	lefthastk(int n, t_time time, t_philo *data)
{
		muts(mut_lock ,data->print);
	if (data->fa->diedd == 1)
		msg(time, TAKE_FORKS, n);
	muts(mut_unlock ,data->print);
}

