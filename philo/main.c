#include "philo.h"
#include <stdio.h>




void	helpful_call(t_philo *data, int *i)
{
	if (data->ts_eats == -1)
		*i = -2;
	else
		*i = 0;
	if (data->key % 2 == 0)
		usleep(1000);
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
	helpful_call(data, &i);
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

void	full_again(t_philo *data, char **av, int i, int ac)
{
	data->philo_num = i;
	data->ttd = ft_atoi(av[2]);
	data->tte = ft_atoi(av[3]);
	data->tts = ft_atoi(av[4]);
	if (ac == 6)
		data->ts_eats = ft_atoi(av[5]);
	else
		data->ts_eats = -1;
}

void	full_data(t_philo *data, char **av, int ac)
{
	int		i;
	int		j;
	t_fa	*fa;

	j = 0;
	i = ft_atoi(av[1]);
	fa = malloc(sizeof(t_fa));
	if (!fa)
		return ;
	fa->diedd = 1;
	if (i == 1)
	{
		philo_one(av);
		data[j].fa = fa;
		return ;
	}
	while (j < i)
	{
		full_again(&data[j], av, i, ac);
		data[j].fa = fa;
		if (pthread_create(&data[j].a_th, NULL, &routine, &data[j]) != 0)
			printf("Error creating thread\n");
		j++;
	}
}
int	ft_render(int ac , char **av , int n)
{
	int	s_t;
	t_philo			*data;
	t_mut	*forchettes;
	t_mut	forkk;
	s_t = ft_atoi(av[1]);
	printf("%d",s_t);
	data = malloc(sizeof(t_philo) * s_t );
		if (!data)
			return (1);
	forchettes = malloc(sizeof(t_mut) * s_t);
		if (!forchettes)
			return (1);
	pthread_mutex_init(&forkk, NULL);
	lunch(forchettes, data, forkk, n);
	full_data(data, av, ac);
	finishing(data, forchettes, av);
	free_mem(data, forchettes);
	pthread_mutex_destroy(&forkk);
	return (0);
}

int	main(int ac, char **av)
{
	int	n;

	if (ac == 5 || ac == 6)
	{
		n = ft_atoi(av[1]);
		if (parcer(av, ac) )
				return (1);
		if (ft_render(ac , av , n))
			return (1);
	}else
		printf("what s hill !!");
	return (0);
}
