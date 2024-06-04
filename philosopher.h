/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:12:30 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/04 21:07:30 by ynassibi         ###   ########.fr       */
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

typedef enum s_obj
{
   mut_lock,
   mut_unlock,
   mut_init,
   mut_des
}t_obj;

void  *my_malloc(unsigned long sb);
void  muts(t_obj obj, t_mut *mut);
int	ft_atoi(const char *str);
int	ins_range(long n);
int	is_digit(char *s);
int	ft_isnumber(char *av);
void	init(t_tb *tb, int ac, char *av[]);
void	checker_parcing(int flag);
