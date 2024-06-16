


#include "philo.h"
#include <stdlib.h>


static void	ft_fill_arr(int *arr, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - 1)
		arr[i++] = ft_atoi(av[j++]);
}

int	t_mutfork_key(int *arr, t_mut *frk, t_mut fk , t_philo *pht)
{
	int	ii;

	ii = -1;

	muts(mut_init,&fk);
	while(++ii < arr[0] )
		muts(mut_init,&frk[ii]);
	ii = -1;
	while (++ii < arr[0])
	{
		pht[ii].print = &fk;
		pht[ii].key = (ii + 1);
		pht[ii].right_fork = &frk[(ii + 1) %  arr[0]];
		pht[ii].left_fork = &frk[ii];
	}
	return (1);
}


t_mut	*init(t_philo *tb, int ac, char *av[],t_mut fk)
{
	int	i;
	int	*arr;
	t_mut	*frk;

	arr = malloc(sizeof(int) * (ac - 1));
	ft_fill_arr(arr, ac, av);
	frk = malloc(sizeof(t_mut) * ft_atoi(av[1]));
	t_mutfork_key(arr, frk, fk, tb);
	i = 0;
	tb->philo_num = arr[i++];
	tb->ttd = arr[i++];
	tb->tte = arr[i++];
	tb->tts = arr[i++];
	if (ac == 6)
		tb->ts_eats = arr[i];
	else
		tb->ts_eats = i - 1337;
	free(arr);
	return (frk);
}
