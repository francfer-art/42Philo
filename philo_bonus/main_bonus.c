/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:52:29 by francfer          #+#    #+#             */
/*   Updated: 2024/04/20 10:46:42 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo_bonus.h"

void	print_struct(t_table *table)
{
	printf("Número de filos!%d\n", table->philo_amount);
	printf("Tiempo para morir!%d\n", table->time_to_die);
	printf("Tiempo para comer!%d\n", table->time_to_eat);
	printf("Tiempo para dormir!%d\n", table->time_to_sleep);
	printf("Límite de comidas!%d\n", table->meal_amount);
}

int	main(int args, char **argv)
{
	t_table	*table;

	if (!is_correct_input(args, argv))
		return (printf("Error: Invalid Arguments\n"), 1);
	table = init(args, argv);
	if (!table)
		return (1);
	table->start_time = get_time();
	start_philo(table);
	return (0);
}
