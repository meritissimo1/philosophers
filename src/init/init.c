/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:22:03 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/30 15:33:11 by marcrodr         ###   ########.fr       */
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

