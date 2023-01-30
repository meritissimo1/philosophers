/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:25:49 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/30 16:59:56 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_param 		param;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	if (validate_args(argc) || check_args(argc, argv))
		return (1);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	init_struct(&param, philo);
	parser(argv, &param, &forks);
	init_forks(&forks, param.philo_nbr);
	return (0);
}