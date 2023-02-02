/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:55:58 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/02 12:01:57 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_action(t_philo *philo, int action)
{
	long int	time;

	pthread_mutex_lock(philo->params->text);
	time = time_calculator(philo->params->start_time);
	if (who_died(philo) == 0)
	{
		if (action == FORK)
			printf("\033[0;33m%ld %i has taken a fork\n\033[0m", time,
				philo->name);
		else if (action == EAT)
			printf("\033[0;34m%ld %i is eating\n\033[0m", time, philo->name);
		else if (action == SLEEP)
			printf("\033[0;35m%ld %i is sleeping\n\033[0m", time, philo->name);
		else if (action == THINK)
			printf("\033[0;32m%ld %i is thinking\n\033[0m", time, philo->name);
		else if (action == DIE)
			printf("\033[0;31m%ld %i died\n\033[0m", time, philo->name);
	}
	else if (action == DIE)
		printf("\033[0;31m%ld %i died\n\033[0m", time, philo->name);
	pthread_mutex_unlock(philo->params->text);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(philo->params->who);
	philo->params->is_dead = philo->name;
	pthread_mutex_unlock(philo->params->who);
	print_action(philo, DIE);
}
