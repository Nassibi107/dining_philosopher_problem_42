/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:11:08 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/04 19:31:59 by ynassibi         ###   ########.fr       */
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
