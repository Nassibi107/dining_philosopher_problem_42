
#include "philo.h"

void	sleep_thread(long long n)
{
	long long	t;

	t = get_time();
	while (get_time() - t < n)
	{
		usleep(500);
	}
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

void	lunch(t_mut *forks, t_philo *ph, t_mut a ,int nb)
{
	int		ii;

	ii = -1;
	init_forchettes(forks, nb);
	init_data(ph,forks, nb);
	while (++ii < nb)
			ph[ii].print = &a;

}

void	khouta_b(long long t, long long t_ime2, t_philo *data)
{
	t_ime2 = get_time();
	pthread_mutex_lock(data->print);
	if ((t_ime2 - t) > data->ttd && data->fa->diedd)
	{
		if (data->fa->diedd == 1)
		{
			printf("%lld		%d is died\n", t_ime2 - t, data->key);
			data->fa->diedd = 0;
		}
	}
	pthread_mutex_unlock(data->print);
}


