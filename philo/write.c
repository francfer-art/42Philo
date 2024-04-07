/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:08:51 by francfer          #+#    #+#             */
/*   Updated: 2024/04/07 20:20:35 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void	write_status(t_state code, t_philo *philo)
{
	long	elapsed;

	elapsed = get_time(MILISECOND) - philo->table->start_simulation;
	if (get_int(&philo->philo_mutex, &philo->full))
		return ;
	safe_mutex_handler(&philo->table->write_mutex, LOCK);
	if ((code == TAKE_FIRST_FORK || code == TAKE_SECOND_FORK)
		&& (!simulation_finished(philo->table)))
		printf("%ld" "  %d has taken a fork\n", elapsed, philo->id);
	else if (code == EATING && !simulation_finished(philo->table))
		printf("%ld" "  %d is eating\n", elapsed, philo->id);
	else if (code == SLEEPING && !simulation_finished(philo->table))
		printf("%ld" "  %d is sleeping\n", elapsed, philo->id);
	else if (code == THINKING && !simulation_finished(philo->table))
		printf("%ld" "  %d is thinking\n", elapsed, philo->id);
	else if (code == DIED)
		printf("%ld" "  %d died\n", elapsed, philo->id);
	safe_mutex_handler(&philo->table->write_mutex, UNLOCK);
}
