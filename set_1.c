/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:06:31 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/10 21:09:54 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	setting_repeat(t_tb *tb, int set_to)
{
	muts(mut_lock, &tb->mut_keep_iter);
	tb->keep_iterating = set_to;
	muts(mut_unlock, &tb->mut_keep_iter);
}
void	ft_rip(t_philo *philo, t_state state)
{
	muts(mut_lock, &philo->mut_state);
	if (philo->state != DEAD)
		philo->state = state;
	muts(mut_lock, &philo->mut_state);
}
