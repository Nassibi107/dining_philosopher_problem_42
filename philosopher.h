/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:12:30 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/10 19:33:51 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHER_H
# define PHILOSOPHER_H


# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
#include <unistd.h>
# define WRONG_INPUT 1
# define MALLOC_ERROR 2

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef  pthread_mutex_t  t_mut;

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

struct	s_tb;

typedef struct s_philo
{
	int				key;
	int				c_pla;
	struct s_tb	*data;
	t_state			state;
	t_mut	*left_f;
	t_mut	*right_f;
	t_mut	mut_state;
	t_mut	mut_nb_meals_had;
	t_mut	last_pla_t;
	long		last_eat_time;
}t_philo;

typedef struct s_tb
{
	int				nbr_of_ph;
	int				nbr_limit_pla;
	int				nb_full_p;
	int			keep_iterating;
	long		tte;
	long		ttd;
	long		tts;
	long		t_start_slt;
	t_mut	mut_eat_t;
	t_mut	mut_die_t;
	t_mut	mut_sleep_t;
	t_mut	mut_print;
	t_mut	mut_nb_philos;
	t_mut	mut_keep_iter;
	t_mut	mut_start_time;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_ths;
	t_mut	*forks;
	t_philo			*philos;
}t_tb;

// routine.c
void		*routine(void *philo_p);
bool		philo_died(t_philo *philo);


// time.c
long	ft_time(void);
void	ft_usleep(long tts);
void		sleeper(long tel);

// monitoring.c
void		*all_full_routine(void *data_p);
void		*all_alive_routine(void *data_p);

// eat_1.c
int			eat(t_philo *philo);
void		update_last_meal_time(t_philo *philo);

// eat_2.c
int			take_forks(t_philo *philo);
int			take_right_fork(t_philo *philo);
int			take_left_fork(t_philo *philo);
void		drop_right_fork(t_philo *philo);
void		drop_left_fork(t_philo *philo);

// sleep.c
int			ft_sleep(t_philo *philo);

// think.c
int			think(t_philo *philo);

// getters.c
long	get_die_time(t_tb *data);
long	get_eat_time(t_tb *data);
long	get_sleep_time(t_tb *data);
bool		get_keep_iter(t_tb *data);
long	get_start_time(t_tb *data);
int			get_nb_philos(t_tb *data);
t_state		get_philo_state(t_philo *philo);
int			get_nb_meals_philo_had(t_philo *philo);
long	get_last_eat_time(t_philo *philo);

// setters.c
void		set_keep_iterating(t_tb *data, bool set_to);
void		set_philo_state(t_philo *philo, t_state state);

// utils.c
bool		nb_meals_option(t_data *data);
void		free_data(t_data *data);
void		print_msg(t_data *data, int id, char *msg);
void		print_mut(t_data *data, char *msg);
int			handle_1_philo(t_philo *philo);

#endif
