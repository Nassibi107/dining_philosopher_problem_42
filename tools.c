/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:02:08 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/11 18:38:12 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "philosopher.h"


int	render_philo(t_tb *tb)
{
	int	np;
	int	i;

	np = get_nph(tb);
	i = -1;
	tb->t_start_slt = ft_time();
	while (++i < np)
	{
		if (pthread_create(&tb->philo_ths[i], NULL,
				&routine, &tb->philos[i]))
			return (1);
	}
	if (pthread_create(&tb->monit_all_alive, NULL,
			&all_alive_routine, tb))
		return (1);
	if (nb_meals_option(tb) == true
		&& pthread_create(&tb->monit_all_full, NULL,
			&all_full_routine, tb))
		return (1);
	return (0);
}

int	join_us(t_tb *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nph(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (nb_meals_option(data) == true
		&& pthread_join(data->monit_all_full, NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}

int	philosophers(int argc, char **argv)
{
	t_tb	data;
	if (init_data(&data, argc, argv) != 0)
		return (MALLOC_ERROR);
	init_philos(&data);
	init_forks(&data);
	run_threads(&data);
	join_threads(&data);
	free_data(&data);
	return (0);
}

