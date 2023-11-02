/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:29:18 by joakoeni          #+#    #+#             */
/*   Updated: 2023/07/26 12:56:58 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_p *param)
{
	pthread_mutex_init(&param->a->write_mutex, NULL);
	pthread_mutex_init(&param->a->dead, NULL);
	pthread_mutex_init(&param->a->timeeat, NULL);
	pthread_mutex_init(&param->a->finish, NULL);
}

int	initialize(t_p *param)
{
	int	i;

	i = -1;
	param->a->start_t = actual_time();
	param->a->stop = 0;
	param->a->nb_finish = 0;
	init_mutex(param);
	while (++i < param->a->philo)
	{
		param->ph[i].id = i + 1;
		param->ph[i].ms_eat = param->a->start_t;
		param->ph[i].nb_eat = 0;
		param->ph[i].finish = 0;
		param->ph[i].r_f = NULL;
		pthread_mutex_init(&param->ph[i].l_f, NULL);
		if (param->a->philo == 1)
			return (1);
		if (i == param->a->philo - 1)
			param->ph[i].r_f = &param->ph[0].l_f;
		else
			param->ph[i].r_f = &param->ph[i + 1].l_f;
	}
	return (1);
}

int	check_value(t_initial_param *param)
{
	if (param->philo > 200)
		return (printf("You ask for too much philosophers.\n"), 1);
	if (param->time_die > 2147483647)
		return (printf("Time to die > Int max.\n"), 1);
	if (param->time_eat > 2147483647)
		return (printf("Time to eat > Int max.\n"), 1);
	if (param->time_sleep > 2147483647)
		return (printf("Time to sleep > Int max.\n"), 1);
	if (param->num_run > 2147483647)
		return (printf("You ask for too much run.\n"), 1);
	if (param->philo < 1)
		return (printf("You don't ask for enough philosophers...\n"), 1);
	if (param->time_die < 1)
		return (printf("Bad argument, not doable...\n"), 1);
	if (param->time_eat < 1)
		return (printf("Bad argument, not doable...\n"), 1);
	if (param->time_sleep < 1)
		return (printf("Bad argument, not doable...\n"), 1);
	if (param->num_run < 1 && param->num_run != 0)
		return (printf("Bad argument, not doable...\n"), 1);
	return (0);
}

t_p	*gain_line_lol(t_p *p)
{
	t_initial_param	*param;
	t_philo			*ph;

	param = malloc(sizeof(t_initial_param));
	if (param == NULL)
		return (printf("Malloc error\n"), p);
	ph = malloc(sizeof(t_philo));
	if (ph == NULL)
		return (printf("Malloc error\n"), p);
	p->a = param;
	p->ph = ph;
	return (p);
}

t_p	*init_struct(int argc, char **argv)
{
	t_p				*p;
	t_initial_param	*param;
	t_philo			*ph;

	p = malloc(sizeof(t_p));
	if (p == NULL)
		return (printf("Malloc error\n"), p);
	p = gain_line_lol(p);
	param = p->a;
	ph = p->ph;
	param->philo = ft_atoi(argv[1]);
	param->time_die = ft_atoi(argv[2]);
	param->time_eat = ft_atoi(argv[3]);
	param->time_sleep = ft_atoi(argv[4]);
	if (argc == 6 && ft_atoi(argv[5]) > 0)
		param->num_run = ft_atoi(argv[5]);
	else if (argc == 6 && ft_atoi(argv[5]) < 1)
		param->num_run = -1;
	else
		param->num_run = 0;
	return (p);
}
