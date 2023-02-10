/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:25:49 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/10 14:51:31 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long int	time_converte(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));	
}

long int	time_calculator(long int time)
{
	long int	act_time;

	act_time = time_converte();
	//printf("time %ld - %ld act_time == %ld\n", time, act_time, act_time - time);
	return (act_time - time);
}

int	time_of_death(long int death_time, long int last_meal)
{
	long int	action_time;	

	action_time = time_converte();
	
	//printf("action_time %ld - %ld last_meal == %ld >= %ld death_time -> result %ld\n", action_time, last_meal, action_time - last_meal, death_time, action_time - last_meal);
	if (last_meal != 0)
		if (action_time - last_meal >= death_time)
			return (0);
	return (1);
}

int	death_time(t_philo *philo)
{
	int		to_die;
	long	l_meal;

	pthread_mutex_lock(philo->mutex_meals);
	to_die = philo->params->time2die;
	l_meal = philo->last_meal;
	pthread_mutex_unlock(philo->mutex_meals);
	if (time_of_death(to_die, l_meal) == 0)
		return (0);
	return (1);
}