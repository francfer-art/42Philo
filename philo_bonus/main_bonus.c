/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:33:28 by francfer          #+#    #+#             */
/*   Updated: 2024/04/16 16:17:09 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int args, char **argv)
{
	t_table	table;

	if (is_correct_input(args, argv))
	{
		parsing_input(&table, argv);
		printf("Parseo correcto!\n");
	}
	else
	{
		ft_error("Bad Input, ./philo 5 800 200 200 [5]");
	}
	return (0);
}
