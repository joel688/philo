/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:01:23 by joakoeni          #+#    #+#             */
/*   Updated: 2023/07/24 17:24:25 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>  //thread
# include <stdio.h>    //printf
# include <stdlib.h>   //malloc
# include <sys/time.h> //time
# include <unistd.h>   //usleep

typedef struct t_initial_param
{
	int				philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_run;
	long int		start_t;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead;
	pthread_mutex_t	timeeat;
	pthread_mutex_t	finish;
	int				nb_finish;
	int				stop;
}					t_initial_param;

typedef struct t_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_t		thread_death_id;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	l_f;
	t_initial_param	*pa;
	long int		ms_eat;
	unsigned int	nb_eat;
	int				finish;
}					t_philo;

typedef struct t_p
{
	t_philo			*ph;
	t_initial_param	*a;
}					t_p;

t_p					*init_struct(int argc, char **argv);
long int			ft_atoi(const char *str);
int					check_value(t_initial_param *param);
int					parse_args(int argc, char **argv, t_p *p);
int					initialize(t_p *p);
int					ft_exit(char *str);
void				write_status(char *str, t_philo *ph);
long int			actual_time(void);
void				ft_putstr_fd(char *s, int fd);
void				ft_usleep(long int time_in_ms);
int					threading(t_p *p);
void				algo(t_philo *ph);
int					check_death(t_philo *ph, int i);
int					ft_strlen(char *str);
int					check_param(int argc, char **argv);
#endif
