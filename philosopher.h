/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:17:50 by abarriga          #+#    #+#             */
/*   Updated: 2023/04/22 20:12:50 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_info
{
	int		num_philo;
	int		die;
	int		eat;
	int		sleep;
	int		must_eat;
	time_t	start_time;
}		t_info;

typedef struct s_philo
{
	int				id;
	time_t			last_eat;
	int				meal_count;
	t_info			*info;
	pthread_mutex_t fork;
}		t_philo;

int			check_fill_args(int argc, char **argv, t_info *info);
int			check_arg(char **argv);
time_t		get_time(void);
int			ft_atoi(const char *str);
void		init_philos(t_info *info);

#endif