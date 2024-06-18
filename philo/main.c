#include "philo.h"
#include <stdio.h>



int	ft_render(int ac , char **av , int n)
{
	int	s_t;
	t_philo			*data;
	t_mut	*forchettes;
	t_mut	fk;
	s_t = ft_atoi(av[1]);
	data = malloc(sizeof(t_philo) * s_t );
		if (!data)
			return (1);
	forchettes = malloc(sizeof(t_mut) * s_t);
		if (!forchettes)
			return (1);
	muts(mut_init ,&fk);
	lunch(forchettes, data, fk, n);
	ft_philanthropist(data, av, ac);
	ft_process(s_t, data, forchettes);
	free_mem(data, forchettes);
	muts(mut_des ,&fk);
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
	}
	else
		printf("what s hill !!");
	return (0);
}
