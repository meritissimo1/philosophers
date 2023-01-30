/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:28:40 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/30 15:54:22 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>

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
	pthread_mutex_t *text;
	pthread_mutex_t *who;	
}					t_param;

typedef struct s_philo
{
    int				name;
	long int		last_meal;
	int				meals;
	bool			satisfied;
	int				time_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t *mutex_meals;
	pthread_t		philo_thread;
	t_param			*param;
}					t_philo;

/*********
** UTILS
**********/
int				check_args(int agrc, char **argv);
long long int	ft_itoll(char *str);
int				ft_atoi(const char *str);
int				validate_args(int argc);
int				ft_isdigit(int arg);

/*********
** INIT
**********/
void	init_struct(t_param *param, t_philo *philo);

/*********
** PARSE
**********/
void	parser(char **argv, t_param *param, pthread_mutex_t **fork);


#endif 