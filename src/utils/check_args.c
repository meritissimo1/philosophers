/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:59:54 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/23 16:38:01 by marcrodr         ###   ########.fr       */
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

static int	check_more_args(char **argv, int i)
{
	if (!ft_isdigit(*argv[i]))
	{
		printf("Error:  arguments must be integers.\n");
		return (1);
	}
	else if (ft_atoi(argv[i]) == 0)
	{
		printf("Error: invalid %d° argument, can't be zero -> %s.\n", i, argv[i]);
		return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while ( i < argc)
	{
		if (ft_itoll(argv[i]) > INT_MAX)
		{
			printf("Error: number bigger than maximum integer.\n");
			return (1);
		}
		else if (argv[i][1] == '-')
		{
			printf("Error: negative numbers\n");
			return (1);
		}
		else if (check_more_args(argv, i))
			return (1);
		i++;
	}
	return (0);
}