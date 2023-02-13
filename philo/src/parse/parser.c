/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:39:48 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/08 15:55:02 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	parser(char **argv, t_param *param, pthread_mutex_t **fork)
{
	*fork = NULL;
	param->philo_nbr = ft_atoi(argv[1]);
	param->time2die = ft_atoi(argv[2]);
	param->time2eat = ft_atoi(argv[3]);
	param->time2sleep = ft_atoi(argv[4]);
	if (argv[5])
		param->meals_nbr = ft_atoi(argv[5]);
	else
		param->meals_nbr = 0;
	param->death = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	param->text = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	param->who = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	pthread_mutex_init(param->death, NULL);
	pthread_mutex_init(param->text, NULL);
	pthread_mutex_init(param->who, NULL);
}