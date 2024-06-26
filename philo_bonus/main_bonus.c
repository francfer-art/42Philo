/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:52:29 by francfer          #+#    #+#             */
/*   Updated: 2024/05/12 21:05:14 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo_bonus.h"

int	main(int args, char **argv)
{
	t_table	*table;

	if (!is_correct_input(args, argv))
		return (printf("Error: Invalid Arguments\n"), 1);
	table = init(args, argv);
	if (!table)
		return (1);
	// table->start_time = get_time();
	start_philo(table);
	return (0);
}
