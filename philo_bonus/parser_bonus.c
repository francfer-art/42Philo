/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:34:15 by francfer          #+#    #+#             */
/*   Updated: 2024/04/16 16:16:40 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->time_to_die <= 0 || table->time_to_eat <= 0
		|| table->time_to_sleep <= 0)
		ft_error("Use positive ms!");
	if (argv[5])
		table->limits_of_meals = ft_atol(argv[5]);
	else
		table->limits_of_meals = -1;
}
