/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:59:54 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/19 11:02:19 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("ERROR: Wrong number of params.\n");
		return (1);		
	}		
	return (0);
}