/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:38:54 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/18 15:38:11 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	my_sleep(t_time n)
{
	t_time	tv;

	tv = get_time();
	while (get_time() - tv < n)
	{
		usleep(500);
	}
}

void	lunch(t_mut *forks, t_philo *ph, t_mut a ,int nb)
{
	int		ii;

	ii = -1;
	init_forchettes(forks, nb);
	init_data(ph,forks, nb);
	while (++ii < nb)
			ph[ii].print = &a;

}

void	ft_sheft(t_time t, t_time t_s, t_philo *phs)
{
	t_s = get_time();
	muts(mut_lock,phs->print);
	if ((t_s - t) > phs->ttd && phs->fa->diedd)
	{
		if (phs->fa->diedd == 1)
		{
			printf("%lld		%d is died\n", t_s - t, phs->key);
			phs->fa->diedd = 0;
		}
	}
	muts(mut_unlock ,phs->print);
}


