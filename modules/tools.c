/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:34:16 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/18 12:38:16 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	wait_rte(long long t0, t_philo *data)
{
	long long	t1;

	muts(mut_unlock, data->left_fork);
	muts(mut_unlock, data->right_fork);
	t1 = get_time();
	ft_sleep(data->key, t1 - t0, data);
	if (data->tts > data->ttd && data->fa->diedd)
	{
		my_sleep(data->ttd);
		pthread_mutex_lock(data->print);
		if (data->fa->diedd)
			msg(get_time() - t0, DIED,  data->key);
		data->fa->diedd = 0;
		muts(mut_unlock, data->print);
	}
	my_sleep(data->tts);
	return (get_time());
}

long long	s_rte(long long t0, t_philo *data)
{
	long long	t1;

	t1 = get_time();
	ft_think(data->key, t1 - t0, data);
	if (data->tte > data->ttd && data->key % 2 != 0)
	{
		my_sleep(data->ttd);
		pthread_mutex_lock(data->print);
		if (data->fa->diedd)
			printf("%lld		%d died\n", get_time() - t0, data->key);
		data->fa->diedd = 0;
		pthread_mutex_unlock(data->print);
	}
	pthread_mutex_lock(data->left_fork);
	t1 = get_time();
	lefthastk(data->key, t1 - t0, data);
	pthread_mutex_lock(data->right_fork);
	t1 = get_time();
	lefthastk(data->key, t1 - t0, data);
	t1 = get_time();
	ft_eat(data->key, t1 - t0, data);
	my_sleep(data->tte);
	return (t1);
}
