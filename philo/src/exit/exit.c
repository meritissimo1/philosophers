/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:03:07 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/06 12:07:38 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	free_thread(t_param param, t_philo *philo,
			pthread_mutex_t *forks)
{
	pthread_mutex_destroy(param.text);
	pthread_mutex_destroy(param.who);
	pthread_mutex_destroy(param.death);
	free(param.who);
	free(param.text);
	free(param.death);
	free(forks);
	free(philo);
}
