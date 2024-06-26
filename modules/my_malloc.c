/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:32:57 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/18 16:34:26 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	err_aloc(void)
{
	write(2, "Error!!\n", 9);
	write(2, "mut or my_malloc failler!!\n", 25);
	return;
}

void	muts(t_obj obj, t_mut *mut)
{
	if (obj == mut_lock)
	{
		if (pthread_mutex_lock(mut))
			err_aloc();
	}
	else if (obj == mut_unlock)
	{
		if (pthread_mutex_unlock(mut))
			err_aloc();
	}
	else if (obj == mut_init)
	{
		if (pthread_mutex_init(mut, NULL))
			err_aloc();
	}
	else if (obj == mut_des)
	{
		if (pthread_mutex_destroy(mut))
			err_aloc();
	}
	else
		err_aloc();
}

void	*my_malloc(unsigned long sb)
{
	void	*alc;

	alc = malloc(sb);
	if (!alc)
		err_aloc();
	return (alc);
}
