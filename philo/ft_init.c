


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
