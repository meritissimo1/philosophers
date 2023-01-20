/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:54:56 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/20 16:57:20 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	signal;

	i = 0;
	result = 0;
	signal = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result * 10) + str[i] - '0' >= INT_MAX)
			return (INT_MAX);
		if ((result * 10) + str[i] - '0' <= INT_MIN)
			return (INT_MIN);
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (signal * result);
}
