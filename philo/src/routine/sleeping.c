/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:17:21 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/03 16:17:38 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int sleeping(t_philo *philo)
{
    print_action(philo, SLEEP);
    usleep(philo->params->time2sleep * 1000);
    return (0);
}
