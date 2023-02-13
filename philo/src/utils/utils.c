/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:54:56 by marcrodr          #+#    #+#             */
/*   Updated: 2023/02/13 16:29:51 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
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

long long int	ft_itoll(char *str)
{
	int				i;
	long long int	is_negative;
	long long int	result;

	i = 0;
	is_negative = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= 48) && (str[i] <= 57))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (is_negative * result);
}
