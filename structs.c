/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:50:54 by abarriga          #+#    #+#             */
/*   Updated: 2023/04/22 20:10:37 by abarriga         ###   ########.fr       */
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
	info->philo = p;
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
		if (pthread_create(&info->threads_id[i], 0, routine, &info->philo[i]))
			printf("ERROR");
	}
}