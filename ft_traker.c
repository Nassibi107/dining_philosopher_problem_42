/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:16:14 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/12 18:58:48 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


int	is_philo_full(t_tb *data, t_philo *philo)
{
	int	des;

	des = 0;
	if (getting(philo) >= data->nbr_limit_pla)
		des = 1;
	return (des);
}

int 	is_died(t_philo *philo)
{
	int 		des;
	t_tb		*data;

	data = philo->data;
	des = false;
	if (ft_time() - mut_lpt(philo) > mut_ttd(data)
		&& get_philo_state(philo) != EATING)
	{
		ft_rip(philo, DEAD);
		des = true;
	}
	return (des);
}

void	notify_all_philos(t_tb *data)
{
	t_philo	*philos;
	int		i;
	int		nb_philos;

	nb_philos = get_nph(data);
	philos = data->philos;
	i = -1;
	while (++i < nb_philos)
		ft_rip(&philos[i], DEAD);
}

void	*all_full_routine(void *data_p)
{
	t_tb	*data;
	int		i;
	int		nb_philos;

	data = (t_tb *)data_p;
	i = -1;
	nb_philos = get_nph(data);
	while (++i < nb_philos && get_rep(data))
	{
		usleep(1000);
		if (is_philo_full(data, &data->philos[i]) == false)
			i = -1;
	}
	if (get_rep(data) == true)
	{
		setting_repeat(data, false);
		notify_all_philos(data);
	}
	return (NULL);
}

void	*all_alive_routine(void *data_p)
{
	int		i;
	int		nb_philos;
	t_tb	*data;
	t_philo	*philos;

	data = (t_tb *)data_p;
	philos = data->philos;
	nb_philos = get_nph(data);
	i = -1;
	while (++i < nb_philos && get_rep(data))
	{
		if (is_died(&philos[i]) && get_rep(data))
		{
			print_msg(data, philos[i].key, DIED);
			setting_repeat(data, false);
			notify_all_philos(data);
			break ;
		}
		if (i == nb_philos - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}


