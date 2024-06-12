/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:12:53 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/12 20:25:01 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	lost_fork (t_philo *philo , int f)
{
	if (f  == 1)
		muts(mut_unlock,philo->right_f);
	else
		muts(mut_unlock,philo->left_f);
}

int	get_forks(t_philo *philo, int f)
{
	if (is_died(philo) || get_philo_state(philo) == DEAD)
		return (1);
	if (f == 0)
	{
		muts(mut_lock,philo->left_f);
		print_msg(philo->data, philo->key, TAKE_FORKS);
	}
	else
	{
		muts(mut_lock,philo->left_f);
		print_msg(philo->data, philo->key, TAKE_FORKS);
	}
	return (0);
}

int	my_turn(t_philo *philo)
{
	if (get_nph(philo->data) == 1)
		return (onph(philo));
	if (get_forks(philo , 1) != 0)
		return (1);
	if (get_forks(philo , 0) != 0)
	{
		lost_fork(philo, 1);
		return (1);
	}
	return (0);
}
