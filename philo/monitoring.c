/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:15:33 by francfer          #+#    #+#             */
/*   Updated: 2024/04/07 20:13:14 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

static int	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_int(&philo->philo_mutex, &philo->full))
		return (0);
	elapsed = get_time(MILISECOND) - get_long(&philo->philo_mutex, &philo->last_meal_time);
	t_to_die = philo->table->time_to_die / 1e3;
	if (elapsed > t_to_die)
		return (1);
	return (0);
}

void	*monitor_dinner(void *data)
{
	t_table	*table;
	int		i;

    table = (t_table *)data;
	while (!all_threads_running(&table->table_mutex, &table->threads_number_running, table->philo_numbers))
		;
	while (!simulation_finished(table))
	{
		i = -1;
		while (++i < table->philo_numbers && !simulation_finished(table))
		{
			if (philo_died(table->philos + 1))
			{
				set_int(&table->table_mutex, &table->end_simulation, 1);
				write_status(DIED, table->philos + 1);
			}
		}
	}
	return (NULL);
}