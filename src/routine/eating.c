/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:57:38 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/03 16:14:04 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int eating(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    pthread_mutex_lock(philo->left_fork);
    if (dinner_finish(philo) != 0)
        return (1);
    print_action(philo, FORK);
    print_action(philo, FORK);
    if (dinner_finish(philo) != 0)
        return (1);
    print_action(philo, EAT);
    meals(philo);
    if (dinner_finish(philo) != 0)
        return (1);
    usleep(philo->params->time2eat * 1000);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    return (0);    
}

int sleeping(t_philo *philo)
{
    print_action(philo, SLEEP);
    usleep(philo->params->time2sleep * 1000);
    return (0);
}