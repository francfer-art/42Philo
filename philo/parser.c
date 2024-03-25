/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:37:33 by francfer          #+#    #+#             */
/*   Updated: 2024/03/25 15:47:46 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing_input(t_table *table, char **argv)
{
	int		i;
	long	number;

	i = 1;
	while (argv[i])
	{
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number <= 0)
			ft_error("Numbers out range");
		i++;
	}
	table->philo_numbers = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1000;
	table->time_to_eat = ft_atol(argv[3]) * 1000;
	table->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (table->time_to_die < 60000 || table->time_to_eat < 60000
		|| table->time_to_sleep < 60000)
		ft_error("Use more than 60ms!");
	if (argv[5])
		table->limits_of_meals = ft_atol(argv[5]);
	else
		table->limits_of_meals = -1;
}
