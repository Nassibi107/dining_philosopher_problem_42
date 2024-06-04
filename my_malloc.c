/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:43:40 by ynassibi          #+#    #+#             */
/*   Updated: 2024/06/04 20:05:45 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <pthread.h>

void  muts(t_obj obj, t_mut *mut)
{
   if (obj == mut_lock)
   {
        if (pthread_mutex_lock(mut))
         checker_parcing(5);
   }
   else if (obj == mut_unlock)
   {
      if (pthread_mutex_unlock(mut))
         checker_parcing(5);
   }
   else if (obj == mut_init)
   {
      if (pthread_mutex_init(mut, NULL))
         checker_parcing(5);
   }
   else if (obj == mut_des)
    {
      if (pthread_mutex_destroy(mut))
         checker_parcing(5);
    }
   else
      checker_parcing(5);
}


void *my_malloc(unsigned long sb)
{
   void  *alc;
   alc = malloc(sb);
   if (!alc)
      checker_parcing(1);
   return (alc);
}

