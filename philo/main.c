/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:09:42 by francfer          #+#    #+#             */
/*   Updated: 2024/04/09 13:39:28 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int args, char **argv)
{
	t_table	table;

	if (is_correct_input(args, argv))
	{
		parsing_input(&table, argv);
		data_init(&table);
		dinne									r_start(&table);
		clean(&table);
	}
	else
	{
		ft_error("Bad Input, ./philo 5 800 200 200 [5]");
	}
	return (0);
}
