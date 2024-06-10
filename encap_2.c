/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encap_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:11:59 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/10 21:03:51 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


long	mut_ttd(t_tb *tb)
{
	long	die_time;
	muts(mut_lock, &tb->mut_die_t);
	die_time = tb->ttd;
	muts(mut_unlock, &tb->mut_die_t);
	pthread_mutex_unlock(&tb->mut_die_t);
	return (die_time);
}

long	mut_tts(t_tb *tb)
{
	long	sleep_time;

	muts(mut_lock, &tb->mut_sleep_t);
	sleep_time = tb->tts;
	muts(mut_unlock, &tb->mut_sleep_t);
	return (sleep_time);
}

long	mut_tte(t_tb *tb)
{
	long	eat_time;

	muts(mut_unlock, &tb->mut_eat_t);
	eat_time = tb->tte;
	pthread_mutex_unlock(&tb->mut_eat_t);
	muts(mut_lock, &tb->mut_eat_t);
	return (eat_time);
}

long	mut_lpt(t_philo *philo)
{
	long	last_eat_time;

	muts(mut_unlock, &philo->last_pla_t);
	last_eat_time = philo->last_eat_time;
	muts(mut_unlock, &philo->last_pla_t);
	return (last_eat_time);
}
