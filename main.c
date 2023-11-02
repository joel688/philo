/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:59:57 by joakoeni          #+#    #+#             */
/*   Updated: 2023/07/26 13:11:57 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_p *p)
{
	free(p->ph);
	free(p->a);
	free(p);
	return ;
}

int	ft_exit(char *s)
{
	printf("Error :");
	printf("%s", s);
	return (0);
}

int	check_death2(t_p *param)
{
	pthread_mutex_lock(&param->a->dead);
	if (param->a->stop)
		return (pthread_mutex_unlock(&param->a->dead), 1);
	pthread_mutex_unlock(&param->a->dead);
	return (0);
}

void	stop(t_p *param)
{
	int	i;

	i = -1;
	while (check_death2(param))
		ft_usleep(1);
	while (++i < param->a->philo)
		pthread_join(param->ph[i].thread_id, NULL);
	pthread_mutex_destroy(&param->a->write_mutex);
	i = -1;
	while (++i < param->a->philo)
		pthread_mutex_destroy(&param->ph[i].l_f);
	if (param->a->stop == 2)
		printf("Each philosopher ate %d time(s)\n", param->a->num_run);
	ft_free(param);
	return ;
}

int	main(int argc, char **argv)
{
	t_initial_param	*param;
	t_p				*p;

	if (argc < 5 || argc > 6)
	{
		printf("Bad arguments, send the number of philosopher, time to die,");
		printf(" time to eat, time to sleep, and optionnaly the ");
		printf("number of times each philosopher must eat.\n");
		return (0);
	}
	p = init_struct(argc, argv);
	param = p->a;
	if (check_value(param) == 1 || check_param(argc, argv) == 1)
		return (ft_free(p), 0);
	if (!initialize(p) || !threading(p))
		return (ft_free(p), 0);
	stop(p);
	return (0);
}
