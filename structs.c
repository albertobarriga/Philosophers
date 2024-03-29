/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:50:54 by abarriga          #+#    #+#             */
/*   Updated: 2023/05/01 20:32:52 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_struct(t_info *info)
{
	t_philo	*p;
	int		i;

	i = -1;
	p = malloc(sizeof(t_philo) * info->num_philo);
	if (!p)
		printf("ERROR");
	while (info->num_philo > ++i)
	{
		p[i].id = i;
		p[i].last_eat = get_time();
		p[i].meal_count = 0;
		p[i].info = info;
		pthread_mutex_init(&p[i].fork_l, NULL);
		p[i].fork_r = &p[(i + 1) % info->num_philo].fork_l;
	}
	pthread_mutex_init(&info->lock_philo_die, NULL);
	pthread_mutex_init(&info->lock_meal_count, NULL);
	pthread_mutex_init(&info->lock_last_eat, NULL);
	info->philo = p;
	pthread_mutex_init(&info->print, NULL);
}

void	init_threads(t_info *info)
{
	int	i;

	i = -1;
	info->threads_id = malloc(sizeof(pthread_t) * info->num_philo);
	if (info->threads_id == NULL)
		printf("ERROR");
	while (++i < info->num_philo)
	{
		if (pthread_create(&info->threads_id[i], NULL,
				routine, &info->philo[i]))
			printf("ERROR");
	}
	pthread_create(&info->revisor, NULL, routine_revisor, info);
	pthread_join(info->revisor, NULL);
}

void	*routine_revisor(void *argc)
{
	t_info	*info;
	int		i;
	int		philo_finish;

	info = (t_info *)argc;
	while (1)
	{
		philo_finish = 0;
		i = -1;
		while (++i < info->num_philo)
		{
			philo_finish += check_meals(info, i);
			if (check_die(info, i))
			{
				print_routine(info->philo, 4);
				pthread_mutex_lock(&info->print);
				pthread_mutex_lock(&info->lock_philo_die);
				info->philo_die = 1;
				return (pthread_mutex_unlock(&info->lock_philo_die), NULL);
			}
		}
		if (philo_finish == info->num_philo)
			return (check_finish(info), NULL);
		usleep(500);
	}
}

int	check_die(t_info *info, int i)
{
	pthread_mutex_lock(&info->lock_last_eat);
	if (get_time() - info->philo[i].last_eat > ((time_t)info->die))
	{
		pthread_mutex_unlock(&info->lock_last_eat);
		return (1);
	}
	pthread_mutex_unlock(&info->lock_last_eat);
	return (0);
}

void	join_threads(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		pthread_join(info->threads_id[i], NULL);
}
