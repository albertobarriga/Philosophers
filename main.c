/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:58:04 by abarriga          #+#    #+#             */
/*   Updated: 2023/04/22 17:55:04 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_info	info;

	printf("argc = %d\n", argc);
	if (check_fill_args(argc, argv, &info) == 1)
		printf("ERROR al crear args\n");
	init_philos(&info);
	printf("este es el tiempo: %ld", print_time());
}

int	check_fill_args(int argc, char **argv, t_info *info)
{
	if ((argc == 5 || argc == 6) && check_arg(argv) == 0)
	{
		info->num_philo = ft_atoi(argv[1]);
		info->die = ft_atoi(argv[2]);
		info->eat = ft_atoi(argv[3]);
		info->sleep = ft_atoi(argv[4]);
		info->must_eat = -1;
		if (argc == 6)
		{
			printf("entro en argc=6\n");
			info->must_eat = ft_atoi(argv[5]);
			if (info->must_eat < 1)
				return (1);
		}
		if (info->num_philo <= 0 || info->die <= 0 || info->eat <= 0
			|| info->sleep <= 0)
			return (1);
		return (0);
	}
	return (1);
}

int	check_arg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	printf("Entra en check_num\n");
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long int	print_time(void)
{
	long int		time;
	struct timeval	current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		printf("ERROR en el tiempo");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}