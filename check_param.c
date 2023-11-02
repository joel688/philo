/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:17:07 by joakoeni          #+#    #+#             */
/*   Updated: 2023/07/24 16:35:59 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_only_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	check_param(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i != argc)
	{
		j = is_only_num(argv[i]);
		if (j != 0)
			return (printf("Only numeric characters in args pls...\n"), 1);
		i++;
	}
	return (0);
}
