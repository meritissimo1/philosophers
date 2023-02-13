/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:56:17 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/13 16:29:05 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	routine(t_philo *philo)
{
	if (eating(philo) == 1 || philo->satisfied == true)
		return (1);
	if (sleeping(philo) == 1 || philo->satisfied == true)
		return (1);
	if (thinking(philo) == 1 || philo->satisfied == true)
		return (1);
	return (0);
}
