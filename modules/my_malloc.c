/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:32:57 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/18 12:38:16 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	err_aloc()
{
	write(2 ,"Error!!\n", 9);
	write(2 ,"mut or malloc failler!!\n", 25);
	exit(EXIT_FAILURE);
}
void  muts(t_obj obj, t_mut *mut)
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
	void  *alc;
	alc = malloc(sb);
	if (!alc)
		err_aloc();
	return (alc);
}



