
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



void	lunch(t_mut *forks, t_philo *ph, t_mut a ,int nb)
{
	int		ii;

	ii = -1;
	init_forchettes(forks, nb);
	init_data(ph,forks, nb);
	while (++ii < nb)
			ph[ii].print = &a;

}

void	ft_sheft(long long t, long long t_s, t_philo *phs)
{
	t_s = get_time();
	muts(mut_lock,phs->print);
	if ((t_s - t) > phs->ttd && phs->fa->diedd)
	{
		if (phs->fa->diedd == 1)
		{
			printf("%lld		%d is died\n", t_s - t, phs->key);
			phs->fa->diedd = 0;
		}
	}
	muts(mut_unlock ,phs->print);
}


