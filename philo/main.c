#include "philo.h"
#include <stdio.h>



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
