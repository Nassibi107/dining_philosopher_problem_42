/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:02:08 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/12 20:34:16 by ynassibi         ###   ########.fr       */
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
	if (nb_meals_option(tb) == 1
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


int	onph(t_philo *philo)
{
	get_forks(philo, 0);
	ft_usleep(mut_ttd(philo->data));
	ft_rip(philo, DEAD);
	return (1);
}

int	nb_meals_option(t_tb *ph)
{
	if (ph->nbr_limit_pla > 0)
		return (1);
	return (0);
}



void	print_msg(t_tb *data, int id, char *msg)
{
	uint64_t	time;

	time = ft_time() - get_timer(data);
	pthread_mutex_lock(&data->mut_print);
	if (get_rep(data))
		printf("%llu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}

// void	print_mut(t_data *data, char *msg)
// {
// 	pthread_mutex_lock(&data->mut_print);
// 	printf("%s\n", msg);
// 	pthread_mutex_unlock(&data->mut_print);
// }
