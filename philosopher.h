/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:17:50 by abarriga          #+#    #+#             */
/*   Updated: 2023/04/25 19:04:57 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_info
{
	int				num_philo;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	time_t			start_time;
	t_philo			*philo;
	pthread_t		*threads_id;
	pthread_t		revisor;
	int				philo_die;
	pthread_mutex_t	print;
}		t_info;

typedef struct s_philo
{
	int				id;
	time_t			last_eat;
	int				meal_count;
	t_info			*info;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	lock_last_eat;
	pthread_mutex_t	lock_meal_count;
}		t_philo;

int			check_fill_args(int argc, char **argv, t_info *info);
int			check_arg(char **argv);
time_t		get_time(void);
int			check_meals(t_info *info, int i);

/*utils.c*/
int			ft_atoi(const char *str);
void		ft_sleep(time_t period, t_info *info);
void		print_routine(t_philo *p, int i);
void		ft_clean(t_info *info);

/*structs.c*/
void		init_struct(t_info *info);
void		init_threads(t_info *info);
void		*routine_revisor(void *argc);
void		join_threads(t_info *info);
int			check_die(t_info *info, int i);

/*routine.c*/
void		*routine(void *arg);
void		take_fork(t_philo *p);
void		eat(t_philo *p);
void		rout_sleep(t_philo *p);
void		think(t_philo *p);

#endif