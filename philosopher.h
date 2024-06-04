/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:12:30 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/04 19:22:52 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/_pthread/_pthread_t.h>
#include <sys/time.h>
#include <limits.h>


typedef  pthread_mutex_t  t_mut;
typedef struct s_philo t_philo;
typedef struct s_forechette
{
   t_mut forechette;
   int   forechette_key;

}  t_forechette;

typedef struct s_tb
{
   long nbr_of_ph;
   long ttd;
   long tte;
   long tts;
   long nbr_limit_pla;
   long t_start_slt;
   long tb_destroy;
   t_philo *pls;
   t_forechette *fork;
}  t_tb;


struct s_philo
{
   int   key;
   long  c_pla;
   bool  done;
   long   last_pla_t;
   t_forechette *left_fork;
   t_forechette *right_fork;
   t_tb  *table;
   pthread_t r_philo;
} ;

int	ft_atoi(const char *str);
int	ins_range(long n);
int	is_digit(char *s);
int	ft_isnumber(char *av);
int	init(t_tb *tb, int ac, char *av[]);
