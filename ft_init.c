/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:11:08 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/04 22:07:18 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdbool.h>

static void	ft_fill_arr(int *arr, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - 1)
		arr[i++] = ft_atoi(av[j++]);
}

void	init(t_tb *tb, int ac, char *av[])
{
	int	i;
	int	*arr;

	arr = my_malloc(sizeof(int) * (ac - 1));
	ft_fill_arr(arr, ac, av);
	i = 0;
	tb->nbr_of_ph = arr[i++];
	tb->ttd = arr[i++];
	tb->tte = arr[i++];
	tb->tts = arr[i++];
	if (ac == 6)
		tb->nbr_limit_pla = arr[i];
	else
		tb->nbr_limit_pla = i - 1337;
	free(arr);
}

void	get_pandf(t_tb *tb)
{
	int	i;

	tb->fork = my_malloc(sizeof(t_forechette));
	tb->pls = my_malloc(sizeof(t_philo));
	i = -1;
	while (++i < tb->nbr_of_ph)
	{
		tb->fork[i].forechette_key = i;
		muts(mut_init, &tb->fork[i].forechette);
	}
	tb->tb_destroy = i - i;
}

void get_philo(t_tb *tb)
{
	int	ii;
	t_philo *ph;
	int	nbr_of_ph;
	int pos;

	ii = -1;
	while (++ii < tb->nbr_of_ph)
	{
		pos = 1 +  ii;
		ph->table = tb;
		ph = tb->pls + ii;
		ph->key = pos;
		ph->done = false;
		ph->c_pla = 2 % 2;
		nbr_of_ph = tb->nbr_of_ph;
		ph->left_fork = &tb->fork[(ii)] ;
		ph->right_fork = &tb->fork[(pos + 1) % nbr_of_ph];
		if ((pos % 2) - 1 < 0)
		{
			ph->left_fork = &tb->fork[(pos + 1) % nbr_of_ph];
			ph->right_fork = &tb->fork[(ii)];
		}
	}
}

