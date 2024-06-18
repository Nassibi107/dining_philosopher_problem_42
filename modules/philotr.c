
#include "../include/philo.h"

static void	ft_fill_arr(int *arr, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - 1)
		arr[i++] = ft_atoi(av[j++]);
}

void	get_data(t_philo *data, int *arr, int n)
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
		get_data(&data[ii], arr, n);
		data[ii].fa = fa;
		if (pthread_create(&data[ii].p_thread, NULL, &routine, &data[ii]) != 0)
			printf("Error creating thread\n");
	}
}

void	ft_philanthropist(t_philo *data, char **av, int n)
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
	fa->diedd = LIFE;
	if (arr[0] == 1)
	{
		no_tb(arr[1]);
		data[j].fa = fa;
	}
	else
		ft_create(arr, data, fa, n);

	free(arr);
}
