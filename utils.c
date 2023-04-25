/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:38:47 by abarriga          #+#    #+#             */
/*   Updated: 2023/04/25 19:17:48 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(const char *str)
{
	int	s;
	int	res;
	int	i;

	s = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * s;
	return (res);
}

void	ft_sleep(time_t period, t_info *info)
{
	time_t	time_now;

	(void)info;
	time_now = get_time();
	while ((get_time() - time_now) < period)
		usleep(500);
}

void	print_routine(t_philo *p, int i)
{
	char	*routine;

	if (i == 0)
		routine = "has taken a fork";
	else if (i == 1)
		routine = "is eating";
	else if (i == 2)
		routine = "is sleeping";
	else if (i == 3)
		routine = "is thinking";
	else
		routine = "died";
	pthread_mutex_lock(&p->info->print);
	printf("%ld %d %s\n", (get_time() - p->info->start_time),
		p->id + 1, routine);
	pthread_mutex_unlock(&p->info->print);
}

void	ft_clean(t_info *info)
{
	int	i;

	i = -1;
	free(info->threads_id);
	free(info->philo);
	pthread_mutex_destroy(&info->print);
	while (++i < info->num_philo)
	{
		pthread_mutex_destroy(&info->philo[i].fork_l);
		pthread_mutex_destroy(&info->philo[i].lock_last_eat);
		pthread_mutex_destroy(&info->philo[i].lock_meal_count);
	}
}
