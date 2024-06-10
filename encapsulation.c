/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encapsulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:00:43 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/10 20:11:29 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_timer(t_tb *data)
{
	long	time;

	muts(mut_lock,&data->mut_start_time);
	time = data->t_start_slt;
	muts(mut_unlock,&data->mut_start_time);
	return (time);
}


int	get_rep(t_tb *data)
{
	int	keep_iterating;

	muts(mut_lock,&data->mut_keep_iter);
	keep_iterating = data->keep_iterating;
	muts(mut_unlock,&data->mut_keep_iter);
	return (keep_iterating);
}

int	get_nph(t_tb *data)
{
	int	nb_philos;

	muts(mut_lock,&data->mut_nb_philos);
	nb_philos = data->nbr_of_ph;
	muts(mut_unlock,&data->mut_nb_philos);
	return (nb_philos);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	s;

	muts(mut_lock,&philo->mut_state);
	s = philo->state;
	muts(mut_lock,&philo->mut_state);
	return (s);
}

int	getting(t_philo *philo)
{
	int	nb_meals_had;

	muts(mut_lock,&philo->mut_nb_meals_had);
	nb_meals_had = philo->c_pla;
	muts(mut_unlock,&philo->mut_nb_meals_had);
	return (nb_meals_had);
}

