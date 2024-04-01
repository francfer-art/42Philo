/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:35:43 by francfer          #+#    #+#             */
/*   Updated: 2024/04/01 12:44:13 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_int(pthread_mutex_t *mutex, int *dest, int value)
{
	safe_mutex_handler(mutex, LOCK);
	*dest = value;
	safe_mutex_handler(mutex, UNLOCK);
}

int	get_int(pthread_mutex_t *mutex, int *value)
{
	int	ret;

	safe_mutex_handler(mutex, LOCK);
	ret = *value;
	safe_mutex_handler(mutex, UNLOCK);
	return (ret);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	ret;

	safe_mutex_handler(mutex, LOCK);
	ret = *value;
	safe_mutex_handler(mutex, UNLOCK);
	return (ret);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	safe_mutex_handler(mutex, LOCK);
	*dest = value;
	safe_mutex_handler(mutex, UNLOCK);
}

int	simulation_finished(t_table *table)
{
	return (get_int(&table->table_mutex, &table->end_simulation));
}
