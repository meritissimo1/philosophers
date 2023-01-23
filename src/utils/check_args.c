/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:59:54 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/23 16:13:36 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	validate_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("ERROR: Wrong number of params.\n");
		return (1);		
	}		
	return (0);
}

static int	check_entry_args_b(char **argv, int i)
{
	long int	aux;

	aux = 0;
	if (!ft_isdigit(argv[i]))
	{
		printf("Error: ")
	}
}

int	check_args(int agrc, char **argv)
{
	int	i;

	i = 0;
	while ( i < argc)
	{
		if (ft_itoll(argv[i] > INT_MAX))
		{
			printf("Error: number bigger than maximum integer.\n");
			return (1);
		}
		else if (argv[i][1] == '-')
		{
			printf("Error: negative numbers\n");
			return (1);
		}
				
	}
}