
#include "philo.h"
#include <stdlib.h>

void	init_forchettes(t_mut *forchettes, int size)
{
	int	ii;

	ii = -1;
	while (++ii < size)
		muts(mut_init ,&forchettes[ii]);
}
void	init_data(t_philo *ph,t_mut *forchettes ,int size)
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

static void	ft_fill_arr(int *arr, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - 1)
		arr[i++] = ft_atoi(av[j++]);
}

void	full_again(t_philo *data, int *arr, int n)
{
	int	ii;
	ii = 0;
	data->philo_num = arr[ii++];
	data->ttd =arr[ii++];
	data->tte = arr[ii++];
	data->tts = arr[ii++];

	if (n == 6)
		data->ts_eats = arr[ii];
	else
		data->ts_eats = -1332 + 42;

}
void ft_create(int *arr,t_philo *data, t_fa *fa,int n)
{
	int	ii;

	ii  = -1;
	while (++ii < arr[0])
	{
		full_again(&data[ii], arr, n);
		data[ii].fa = fa;
		if (pthread_create(&data[ii].a_th, NULL, &routine, &data[ii]) != 0)
			printf("Error creating thread\n");
	}
}

void	full_data(t_philo *data, char **av, int n)
{
	int		j;
	t_fa	*fa;
	int	*arr;
	arr = malloc(sizeof(int) * (n - 1));
	if (!arr)
		return ;
	ft_fill_arr(arr, n, av);
	j = 0;
	fa = malloc(sizeof(t_fa));
	if (!fa)
		return ;
	fa->diedd = 1;
	if (arr[0] == 1)
	{
		philo_one(av);
		data[j].fa = fa;
	}
	else
		ft_create(arr, data, fa, n);

	free(arr);
}

void	finishing(t_philo *data, t_mut *forks, char **av)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	k = ft_atoi(av[1]);
	while (i < k)
	{
		pthread_join(data[i].a_th, NULL);
		i++;
	}
	i = 0;
	while (i < k)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
