
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:57:39 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/03 16:49:47 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	err(int flag)
{
	if (flag == 0)
		write(2, "what ever!\n", 11);
	if (flag == 1)
		write(2, "memory problem !please clean your device\n", 17);
	if (flag == 2)
		write(2, "Creating threads Failed!\n", 26);
	if (flag == 3)
		write(2, "Joing threads Failed!\n", 23);
	if (flag == 4)
		write(2, "Program Failed!\n", 17);
	exit(EXIT_FAILURE);
}
void	checker_parcing(int flag)
{
	write(2, "!----{_ERROR_}-----!\n", 21);
	if (flag == 0)
		write(2, "what ever!\n", 11);
	if (flag == 1)
		write(2, "memory problem please clean your device\n", 16);
	if (flag == 2)
		write(2, "Creating threads Failed!\n", 26);
	if (flag == 3)
	{
		write(2, "check if {{number}} \n! ", 22);
		write(2, "it must be in [0, 2222222]\n", 28);
		write(2, "aren't digits\n", 12);
	}
	if (flag == 6)
		write(2, "Joing threads Failed!\n", 23);
	if (flag == 4)
		write(2, "Program Failed!\n", 17);
	if (flag == 5)
		write(2, "Creating Mutex Failed!\n", 24);
	exit(1);
}

int	main(int ac, char **av)
{
	int		i;
	t_tb	*tb ;

	tb = malloc(sizeof(t_tb));
	if (!tb)
		err(2);
	i = 1;
	if (ac == 5 || ac == 6)
	{
		while (i < ac)
		{
			if (ft_isnumber(av[i]) == 1)
				checker_parcing(3);
			i++;
		}
	init(tb, ac, av);
	// dug init

		printf("{nbr_of_ph:%d}\t",tb->nbr_of_ph);
		printf("{ttd:%ld}\t",tb->ttd);
		printf("{tte:%ld}\t",tb->tte);
		printf("{tts:%ld}\t",tb->tts);
		printf("{nbr_limit_pla:%d}\t",tb->nbr_limit_pla);
		printf("\n");
		tk_fork(tb);
		render_philo(tb);
		join_us(tb);
	}
	else
		printf("number of arg are notValid");
}
