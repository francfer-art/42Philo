/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:38:24 by francfer          #+#    #+#             */
/*   Updated: 2024/04/24 18:08:16 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_meal(void *data)
{
	t_table	*table;
	int		eat_counter;
	int		i;

	table = (t_table *)data;
	eat_counter = 0;
	while (eat_counter < table->meal_amount)
	{
		i = -1;
		while (++i <= table->philo_amount)
			sem_wait(table->sem_meal);
		eat_counter++;
	}
	sem_wait(table->sem_write);
	i = -1;
	while (++i < table->philo_amount)
		kill(table->philos[i]->philo_pid, SIGKILL);
	return (NULL);
}

void	*monitor_die(void *arg)
{
	t_philo	*ph;

	ph = ((t_philo *)arg);
	while (1)
	{
		sem_wait(ph->sem_eat);
		if (get_time() - ph->last_meal_time >= ph->table->time_to_die)
		{
			message(ph->table, ph->philo_id, DIED);
			exit(1);
		}
		sem_post(ph->sem_eat);
		usleep(100);
	}
	return (NULL);
}
