/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:51:32 by francfer          #+#    #+#             */
/*   Updated: 2024/04/09 12:46:29 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_table *table)
{
	while (!get_int(&table->table_mutex, &table->all_threads_ready))
		;
}

void	increase_long(pthread_mutex_t *mutex, long *value)
{
	safe_mutex_handler(mutex, LOCK);
	(*value)++;
	safe_mutex_handler(mutex, UNLOCK);
}

int	all_threads_running(pthread_mutex_t *mutex, long *threads, long philo_nbr)
{
	safe_mutex_handler(mutex, LOCK);
	if (*threads == philo_nbr)
		return (1);
	safe_mutex_handler(mutex, UNLOCK);
	return (0);
}

void	de_synchro_philos(t_philo *philo)
{
	if (philo->table->philo_numbers % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(3e4, philo->table);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, 1);
	}
}