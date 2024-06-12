/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:11:08 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/12 20:47:26 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	ft_fill_arr(int *arr, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - 1)
		arr[i++] = ft_atoi(av[j++]);
}

int	init(t_tb *tb, int ac, char *av[])
{
	int	i;
	int	*arr;

	arr = malloc(sizeof(int) * (ac - 1));
	if (!arr)
		return (0);
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
	return (1);
}
int	tk_fork(t_tb *tb)
{
	int		i;
	t_philo	*philos;

	philos = tb->philos;
	i = -1;
	while (++i < tb->nbr_of_ph)
		muts(mut_init ,&tb->forks[i]);
	i = 0;
	philos[0].left_f = &tb->forks[0];
	philos[0].right_f = &tb->forks[tb->nbr_of_ph - 1];
	while (++i < tb->nbr_of_ph)
	{
		philos[i].left_f = &tb->forks[i];
		philos[i].right_f = &tb->forks[i - 1];
	}
	return (0);
}
