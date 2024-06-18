
#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		sec;
	long long		usec;

	gettimeofday (&time, NULL);
	sec = time.tv_sec * 1e3;
	usec = time.tv_usec * 0.001;
	return (usec + sec);
}
