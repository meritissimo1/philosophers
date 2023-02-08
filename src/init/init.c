/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:22:03 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/08 11:13:16 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	init_struct(t_param *param, t_philo *philo)
{
	philo->name = 0;
	philo->meals = 0;
	philo->last_meal = 0;
	philo->satisfied = false;
	philo->time_eaten = 0;
	param->is_dead = 0;
	param->philo_nbr = 0;
	param->time2die = 0;
	param->time2eat = 0;
	param->time2sleep = 0;
	param->meals_nbr = 0;
	param->start_time = 0;	
}

void	init_forks(pthread_mutex_t **forks, int philos)
{
	int i;

	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philos);
	i = -1;
	while ( ++i < philos)
		pthread_mutex_init(&(*forks)[i], NULL);
}

void	init_philosophers(t_philo *philo, t_param *param,
		pthread_mutex_t **forks, int qqt_philo)
{
	pthread_t	waiter;
	int			i;

	i = -1;
	while (++i < qqt_philo)
	{
		philo[i].name = i + 1;
		philo[i].right_fork = &(*forks)[i];
		philo[i].left_fork = &(*forks)[i + 1];
		philo[i].mutex_meals = (pthread_mutex_t *)
			malloc(sizeof(pthread_mutex_t) * 1);
		pthread_mutex_init(philo[i].mutex_meals, NULL);
		philo[i].params = param;
	}
	philo[i - 1].left_fork = &(*forks)[0];
	i = -1;
	param->start_time = time_converte();
	while (++i < qqt_philo)
	{
		pthread_create(&philo[i].philo_thread, NULL, &dinner,
			(void *)&philo[i]);
		printf("Thread %d has started \n", i);		
	}
		
	pthread_create(&waiter, NULL, &end_dinner, philo);
	i = -1;
	while (++i < qqt_philo)
	{
		pthread_join(philo[i].philo_thread, NULL);
		printf("thread %d has finished \n", i);
	}
		
	pthread_join(waiter, NULL);
}