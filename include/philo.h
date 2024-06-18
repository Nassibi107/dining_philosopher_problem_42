/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:36:17 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/18 15:53:55 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define LIFE 1
# define DEATH 0
# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef long long		t_time;
typedef pthread_mutex_t	t_mut;

typedef struct s_fa
{
	int	deb;
	int	diedd;
}	t_fa;

typedef struct s_philo
{
	t_mut			*left_fork;
	t_mut			*right_fork;
	t_mut			*print;
	pthread_t		p_thread;
	int				key;
	int				philo_num;
	int				ttd;
	int				tte;
	int				tts;
	int				ts_eats;
	struct s_fa		*fa;
	t_time			t;
}	t_philo;

typedef enum s_obj
{
	mut_lock,
	mut_unlock,
	mut_init,
	mut_des
}	t_obj;

typedef struct s_tools
{
	t_time	t0;
	t_time	t1;
	int		ii;
}	t_tools;

void	msg(t_time time, char *s, int key);
int		parcer(char **av, int ac);
void	init_data(t_philo *ph, t_mut *forchettes, int size);
void	init_forchettes(t_mut *forchettes, int size);
void	muts(t_obj obj, t_mut *mut);
int		t_mutfork_key(int *arr, t_mut *frk, t_mut fk, t_philo *pht);
int		ft_atoi(const char *str);
t_time	get_time(void);
void	ft_think(int n, t_time dif, t_philo *data);
void	lefthastk(int n, t_time dif, t_philo *data);
void	ft_sleep(int n, t_time dif, t_philo *data);
void	ft_eat(int n, t_time dif, t_philo *data);
t_time	wait_rte(t_time t_ime, t_philo *data);
t_time	s_rte(t_time t_ime, t_philo *data);
void	my_sleep(t_time e);
void	ft_process(int n, t_philo *ph, t_mut *forks);
void	lunch(t_mut *forks, t_philo *ph, t_mut a, int nb);
void	get_data(t_philo *data, int *arr, int n);
int		check_arg(char **av);
void	no_tb(int e);
void	ft_sheft(t_time t, t_time t_ime2, t_philo *data);
t_mut	*init(t_philo *tb, int ac, char *av[], t_mut fk);
void	*routine(void *arg);
void	ft_process(int n, t_philo *data, t_mut *forks);
void	ft_philanthropist(t_philo *data, char **av, int ac);

#endif
