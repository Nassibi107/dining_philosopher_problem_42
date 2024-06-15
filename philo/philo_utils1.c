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

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday (&time, NULL);
	return (((time.tv_sec * 1e3) + (time.tv_usec * 0.001)));
}
