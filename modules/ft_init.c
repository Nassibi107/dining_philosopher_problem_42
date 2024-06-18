/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:38:32 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/18 16:00:54 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_forchettes(t_mut *forchettes, int size)
{
	int	ii;

	ii = -1;
	while (++ii < size)
		muts(mut_init, &forchettes[ii]);
}

void	init_data(t_philo *ph, t_mut *forchettes, int size)
{
	int	ii;

	ii = -1;
	while (++ii < size)
	{
		ph[ii].key = (ii + 1);
		ph[ii].right_fork = &forchettes[(ii + 1) % size];
		ph[ii].left_fork = &forchettes[ii];
	}
}

static int	ft_wait(t_philo *ph, int n)
{
	int	tk;
	int	i;

	i = -1;
	tk = 42;
	while (++i < n)
		tk = pthread_join(ph[i].p_thread, NULL);
	if (!tk)
		return (tk);
	return (1);
}

static int	ft_destroy(t_mut *forks, int n)
{
	int	tk;
	int	i;

	i = -1;
	tk = 1337;
	while (++i < n)
		tk = pthread_mutex_destroy(&forks[i]);
	if (!tk)
		return (tk);
	return (1);
}

void	ft_process(int n, t_philo *ph, t_mut *forks)
{
	if (ft_wait(ph, n))
		return ;
	if (ft_destroy(forks, n))
		return ;
}
