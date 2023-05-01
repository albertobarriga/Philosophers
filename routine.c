/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:36:28 by abarriga          #+#    #+#             */
/*   Updated: 2023/05/01 18:16:31 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2)
		usleep(250);
	while (all_alive(p->info))
	{
		take_fork(p);
		eat(p);
		rout_sleep(p);
	}
	return (NULL);
}

int	all_alive(t_info *info)
{
	pthread_mutex_lock(&info->lock_philo_die);
	if (info->philo_die == 0)
		return (pthread_mutex_unlock(&info->lock_philo_die), 1);
	return (pthread_mutex_unlock(&info->lock_philo_die), 0);
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
	pthread_mutex_lock(&p->info->lock_last_eat);
	p->last_eat = get_time();
	pthread_mutex_unlock(&p->info->lock_last_eat);
	pthread_mutex_lock(&p->info->lock_meal_count);
	p->meal_count += 1;
	pthread_mutex_unlock(&p->info->lock_meal_count);
	pthread_mutex_unlock(&p->fork_l);
	pthread_mutex_unlock(p->fork_r);
}

void	rout_sleep(t_philo *p)
{
	print_routine(p, 2);
	ft_sleep(p->info->sleep, p->info);
	print_routine(p, 3);
}
