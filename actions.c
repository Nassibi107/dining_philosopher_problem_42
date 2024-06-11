/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:11:17 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/11 18:30:22 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	eat(t_philo *philo)
{
	if (take_forks(philo) != 0)
		return (1);
	ft_rip(philo, 2);
	print_msg(philo->data, philo->key, EAT);
	muts(mut_lock,&philo->last_pla_t);
	philo->last_eat_time = ft_time();
	muts(mut_unlock,&philo->last_pla_t);
	ft_usleep(get_eat_time(philo->data));
	muts(mut_lock ,&philo->mut_nb_meals_had);
	philo->c_pla++;
	muts(mut_unlock,&philo->mut_nb_meals_had);
	muts(mut_lock ,philo->left_f);
	muts(mut_unlock ,philo->right_f);
	return (0);
}

int	forks(t_philo *philo)
{
	if (get_nph(philo->data))
		return (handle_1_philo(philo));
	if (philo_died(philo) || get_philo_state(philo) == DEAD)
		return (1);
	else
	{
		pthread_mutex_lock(philo->right_f);
		print_msg(philo->data, philo->key, TAKE_FORKS);
	};
	if (philo_died(philo) || get_philo_state(philo) == DEAD)
	{
		muts(mut_lock ,philo->right_f);
		return (1);
	}
	else
	{
		pthread_mutex_lock(philo->left_f);
		print_msg(philo->data, philo->key, TAKE_FORKS);
	}
	return (0);
}
int	sleeping(t_philo *ph)
{
	ft_rip(ph, SLEEPING);
	if (!get_philo_state(ph))
		return (1);
	print_msg(ph->data, ph->key, SLEEP);
	ft_usleep(get_sleep_time(ph->data));
	return (0);
}

int	thinking(t_philo *ph)
{
	ft_rip(ph, THINKING);
	if (!get_philo_state(ph))
		return (1);
	print_msg(ph->data, ph->key, THINK);
	return (0);
}
