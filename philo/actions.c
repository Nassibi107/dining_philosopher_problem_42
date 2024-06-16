#include "philo.h"

void	ft_eat(int n, long long dif, t_philo *data)
{
	muts(mut_lock ,data->print);
	if (data->fa->diedd == 1)
		printf("%lld		%d is eating\n", dif, n);
	muts(mut_unlock ,data->print);
}

void	ft_sleep(int n, long long dif, t_philo *data)
{
	muts(mut_lock ,data->print);
	if (data->fa->diedd == 1)
		printf("%lld		%d is sleeping\n", dif, n);
	muts(mut_unlock ,data->print);
}

void	ft_think(int n, long long dif, t_philo *data)
{
		muts(mut_lock ,data->print);
	if (data->fa->diedd == 1)
		printf("%lld		%d is thinking\n", dif, n);
	muts(mut_unlock ,data->print);
}

void	lefthastk(int n, long long dif, t_philo *data)
{
		muts(mut_lock ,data->print);
	if (data->fa->diedd == 1)
		printf("%lld		%d has taken left a fork\n", dif, n);
	muts(mut_unlock ,data->print);
}
void	*routine(void *arg)
{
	t_philo			*data;
	int				i;
	long long		t_ime;
	long long		t_ime2;

	data = (t_philo *)arg;
	t_ime = get_time();
	t_ime2 = 0;
	if (data->ts_eats < 0)
		i = -2;
	else
		i = 0;
	if (data->key % 2 == 0)
		usleep(1000);
	while (i < data->ts_eats)
	{
		data->t = start_routine(t_ime, data);
		data->t = rest_routine(t_ime, data);
		khouta_b(data->t, t_ime2, data);
		if (data->fa->diedd == 0)
			return (0);
		if (data->ts_eats == -1)
			continue ;
		else
			i++;
	}
	return (0);
}
long long	get_time(void)
{
	struct timeval	time;

	gettimeofday (&time, NULL);
	return (((time.tv_sec * 1e3) + (time.tv_usec * 0.001)));
}
