/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:36:28 by abarriga          #+#    #+#             */
/*   Updated: 2023/04/25 18:56:34 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2)
		usleep(250);
	while (p->info->philo_die == 0)
	{
		take_fork(p);
		eat(p);
		rout_sleep(p);
		think(p);
	}
	return (NULL);
}

void	take_fork(t_philo *p)
{
	pthread_mutex_lock(&p->fork_l);
	print_routine(p, 0);
	pthread_mutex_lock(p->fork_r);
	print_routine(p, 0);
}

void	eat(t_philo *p)
{
	print_routine(p, 1);
	ft_sleep(p->info->eat, p->info);
	pthread_mutex_lock(&p->lock_last_eat);
	p->last_eat = get_time();
	pthread_mutex_unlock(&p->lock_last_eat);
	pthread_mutex_lock(&p->lock_meal_count);
	p->meal_count += 1;
	pthread_mutex_unlock(&p->lock_meal_count);
	pthread_mutex_unlock(&p->fork_l);
	pthread_mutex_unlock(p->fork_r);
}

void	rout_sleep(t_philo *p)
{
	print_routine(p, 2);
	ft_sleep(p->info->sleep, p->info);
}

void	think(t_philo *p)
{
	print_routine(p, 3);
}
