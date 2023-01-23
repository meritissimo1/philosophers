/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:28:40 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/23 16:37:02 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>

/*********
** UTILS
**********/
int	check_args(int agrc, char **argv);
long long int	ft_itoll(char *str);
int	ft_atoi(const char *str);
int	validate_args(int argc);
int	ft_isdigit(int arg);



#endif 