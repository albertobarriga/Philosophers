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

void init_philos(t_info *info)
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
		pthread_mutex_init(&p[i].fork, NULL);
	}
	
}