/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:58:04 by abarriga          #+#    #+#             */
/*   Updated: 2023/03/06 19:35:12 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
    t_p p;

    if (check_fill_args(argc, argv, &p) == 0)
		printf("ERROR");
	printf("este es el tiempo:%l", print_time());
}

int check_fill_args(int argc, char **argv, t_p *p)
{
    if ((argc >= 5 && argc <= 6) && arg_numeric(argv))
	{
		p->num_philo = ft_atoi(argv[1]);
		p->die = ft_atoi(argv[2]);
		p->eat = ft_atoi(argv[3]);
		p->sleep = ft_atoi(argv[4]);
		p->must_eat = -1;
		if (argc == 6)
			p->must_eat = ft_atoi(argv[5]);
		if (p->num_philo <= 0 || p->die <= 0 || p->eat <= 0 || p->sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

int	check_arg(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long int	print_time(void)
{
	long int 		time;
	struct timeval	current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		printf("ERROR");
	time = 	(current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}