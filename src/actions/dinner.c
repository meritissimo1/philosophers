/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:00:35 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/02 15:09:14 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	one_philo(t_philo *one)
{
	printf("\033[0;33m%ld %i has taken a fork\n\033[0m",
		time_calculator(one->params->start_time), one->name);
	usleep(one->params->time2die * 1000);
	printf("\033[0;31m%ld %i died\n\033[0m",
		time_calculator(one->params->start_time), one->name);
}

void	*dinner(void *arg)
{
	t_philo	*philo_n;

	philo_n = (t_philo *)arg;
	printf ("one philo %i\n", philo_n->params->philo_nbr);
	pthread_mutex_lock(philo_n->mutex_meals);
	philo_n->last_meal = philo_n->params->start_time;
	pthread_mutex_unlock(philo_n->mutex_meals);
	if (philo_n->params->philo_nbr == 1)
	{	
		one_philo(philo_n);
		return (NULL);
	}
	if (philo_n->name % 2 == 0)
		usleep(1000);
}

int	who_died(t_philo *philo)
{
	int	dead;

	dead = 0;
	pthread_mutex_lock(philo->params->who);
	dead = philo->params->is_dead;
	pthread_mutex_unlock(philo->params->who);
	return (dead);
}

static int	verify(t_philo *philo)
{
	int	i;

	i = -1;
	if (who_died(philo))
		return (1);
	if (death_time(philo) == 0 && philo->satisfied == false)
	{
		pthread_mutex_lock(philo->params->death);
		if (who_died(philo) == 0 && philo->params->philo_nbr != 1)
			print_death(philo);
		pthread_mutex_unlock(philo->params->death);
		return (1);
	}
	if (philo->params->meals_nbr != 0)
	{
		while (++i < philo->params->philo_nbr)
		{
			if (philo[i].meals != philo->params->meals_nbr)
				return (0);
		}
		return (1);
	}
	return (0);
}

void	*end_dinner(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	while (!verify(philo))
		continue ;
	return (NULL);	
}