#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_p
{
	t_philo	*philo;
	t_info	info;
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
