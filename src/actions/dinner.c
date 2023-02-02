/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:00:35 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/02 11:11:29 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void *dinner(void *arg)
{
	t_philo	*philo_n;

	philo_n = (t_philo *)arg;
	printf ("one philo %i\n", philo_n->param->philo_nbr);
	pthread_mutex_lock(philo_n->mutex_meals);
	philo_n->last_meal = philo_n->param->start_time;
	pthread_mutex_unlock(philo_n->mutex_meals);
	if (philo_n->param->philo_nbr == 1)
		printf ("one philo\n");
	return (NULL);
}
