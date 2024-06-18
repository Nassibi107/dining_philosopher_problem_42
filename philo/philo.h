#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define SUCESS 1
# define FAILURE 0
typedef  pthread_mutex_t  t_mut;

typedef struct s_fa
{
	int	deb;
	int				diedd;
}	t_fa;

typedef struct s_philo
{
	t_mut	*left_fork;
	t_mut	*right_fork;
	t_mut	*print;
	pthread_t		a_th;
	int				key;
	int				philo_num;
	int				ttd;
	int				tte;
	int				tts;
	int				ts_eats;
	struct s_fa		*fa;
	long long		t;
}	t_philo;


typedef enum s_obj
{
	mut_lock,
	mut_unlock,
	mut_init,
	mut_des
}t_obj;
void	init_data(t_philo *ph,t_mut *forchettes ,int size);
void	init_forchettes(t_mut *forchettes, int size);
int	parcer(char **av , int ac);
void	muts(t_obj obj, t_mut *mut);
int	t_mutfork_key(int *arr, t_mut *frk, t_mut fk , t_philo *pht);
int			ft_atoi(const char *str);
long long	get_time(void);
void		ft_think(int n, long long dif, t_philo *data);
void		lefthastk(int n, long long dif, t_philo *data);
void		ft_sleep(int n, long long dif, t_philo *data);
void		ft_eat(int n, long long dif, t_philo *data);
long long	wait_rte(long long t_ime, t_philo *data);
long long	s_rte(long long t_ime, t_philo *data);
void		sleep_thread(long long n);
void	ft_process(int n,t_philo *ph, t_mut *forks);
void	lunch(t_mut *forks, t_philo *ph, t_mut a ,int nb);
void	get_data(t_philo *data, int *arr, int n);
int			check_arg(char **av);
void		philo_one(char **av);
void		ft_sheft(long long t, long long t_ime2, t_philo *data);
void		free_mem(t_philo *data, t_mut *forks);
t_mut		*init(t_philo *tb, int ac, char *av[], t_mut fk);
void	*routine(void *arg);
void	ft_process(int n,t_philo *data, t_mut *forks);
void	ft_philanthropist(t_philo *data, char **av, int ac);

#endif
