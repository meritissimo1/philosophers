/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:25:49 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/30 12:34:01 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_philo	*philo;

	printf("argc: %d\nargv: %s\n\n", argc, argv[1]);
	if (validate_args(argc) || check_args(argc, argv))
		return (1);
	philo = malloc(sizeof(t_philo) *ft_atoi(argv[1]));	
	return (0);
}