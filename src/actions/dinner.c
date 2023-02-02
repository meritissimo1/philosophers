/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:00:35 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/02 11:26:37 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	one_philo(t_philo *one)
{
	printf("\033[0;33.%ld %i has taken a fork\n\033[0m",
		time_calculator(one->param->start_time), one->name);
	usleep(one->param->time2die * 1000);
	printf("\033[0;31.%ld %i died\n\033[0m",
		time_calculator(one->param->start_time), one->name);
}

void	*dinner(void *arg)
{
	t_philo	*philo_n;

	philo_n = (t_philo *)arg;
	printf ("one philo %i\n", philo_n->param->philo_nbr);
	pthread_mutex_lock(philo_n->mutex_meals);
	philo_n->last_meal = philo_n->param->start_time;
	pthread_mutex_unlock(philo_n->mutex_meals);
	if (philo_n->param->philo_nbr == 1)
		one_philo(philo_n);
	return (NULL);
}
