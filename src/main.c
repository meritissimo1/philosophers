/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:25:49 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/06 12:05:39 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_param 		param;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int 			i;

	i = 0;
	if (validate_args(argc) || check_args(argc, argv))
		return (1);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	init_struct(&param, philo);
	parser(argv, &param, &forks);
	init_forks(&forks, param.philo_nbr);
	init_philosophers(philo, &param, &forks, param.philo_nbr);
	while (i < param.philo_nbr && forks)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(philo[i].mutex_meals);
		free(philo[i].mutex_meals);
		i++;
	}
	free_thread(param, philo, forks);
	return (0);
}