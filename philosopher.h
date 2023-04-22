/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:17:50 by abarriga          #+#    #+#             */
/*   Updated: 2023/04/22 16:41:22 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_p
{
	int	id;
}			t_p;

typedef struct s_philo
{
	int	id;
}		t_philo;

typedef struct s_info
{
	int	num_philo;
	int	die;
	int	eat;
	int	sleep;
	int	must_eat;
}		t_info;

int			check_fill_args(int argc, char **argv, t_info *info);
int			check_arg(char **argv);
long int	print_time(void);
int			ft_atoi(const char *str);

#endif