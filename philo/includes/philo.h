/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:28:40 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/14 14:22:43 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK 2
# define EAT 3
# define SLEEP 4
# define THINK 5
# define DIE 6

typedef struct s_param
{
	int				philo_nbr;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				meals_nbr;
	long int		start_time;
	int				is_dead;
	pthread_mutex_t	*death;
	pthread_mutex_t	*text;
	pthread_mutex_t	*who;
}					t_param;

typedef struct s_philo
{
	int				name;
	long int		last_meal;
	int				meals;
	bool			satisfied;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*mutex_meals;
	pthread_t		philo_thread;
	t_param			*params;
}					t_philo;

/*********
** UTILS
**********/
int				check_args(int agrc, char **argv);
long long int	ft_itoll(char *str);
int				ft_atoi(const char *str);
int				validate_args(int argc);
int				ft_isdigit(int arg);
long int		time_converte(void);
long int		time_calculator(long int time);
int				death_time(t_philo *philo);

/*********
* INIT
**********/
void			init_struct(t_param *param, t_philo *philo);
void			init_forks(pthread_mutex_t **forks, int philos);
void			init_philosophers(t_philo *philo, t_param *param,
					pthread_mutex_t **forks, int qqt_philo);

/*********
* PARSE
**********/
void			parser(char **argv, t_param *param, pthread_mutex_t **fork);

/*********
* ACTIONS
**********/
void			*dinner(void *arg);
void			*end_dinner(void *phi);
void			print_death(t_philo *philo);
void			print_action(t_philo *philo, int action);
int				who_died(t_philo *philo);
int				dinner_finish(t_philo *philo);
void			meals(t_philo *philo);

/*********
* ROUTINE
**********/
int				routine(t_philo *philo);
int				eating(t_philo *philo);
int				sleeping(t_philo *philo);
int				thinking(t_philo *philo);

/*********
* EXIT
**********/
void			free_thread(t_param param, t_philo *philo,
					pthread_mutex_t *forks);

#endif