/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:00:20 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/18 15:43:09 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_time	wait_rte(t_time t0, t_philo *data)
{
	t_time	t1;

	muts(mut_unlock ,data->left_fork);
	muts(mut_unlock ,data->right_fork);
	t1 = get_time();
	ft_sleep(data->key, t1 - t0, data);
	if (data->tts > data->ttd && data->fa->diedd)
	{
		my_sleep(data->ttd);
		pthread_mutex_lock(data->print);
		if (data->fa->diedd == LIFE)
			printf("%lld		%d died\n", get_time() - t0, data->key);
		data->fa->diedd = 0;
		muts(mut_unlock ,data->print);
	}
	my_sleep(data->tts);
	return (get_time());
}

t_time	s_rte(t_time t0, t_philo *data)
{
	t_time	t1;

	t1 = get_time();
	ft_think(data->key, t1 - t0, data);
	if (data->tte > data->ttd && data->key % 2 != 0)
	{
		my_sleep(data->ttd);
		muts(mut_unlock,data->print);
		if (data->fa->diedd)
			printf("%lld		%d died\n", get_time() - t0, data->key);
		data->fa->diedd = 0;
		muts(mut_lock ,data->print);
	}
	muts(mut_unlock,data->left_fork);
	t1 = get_time();
	lefthastk(data->key, t1 - t0, data);
	muts(mut_unlock,data->right_fork);
	t1 = get_time();
	lefthastk(data->key, t1 - t0, data);
	t1 = get_time();
	ft_eat(data->key, t1 - t0, data);
	my_sleep(data->tte);
	return (t1);
}
