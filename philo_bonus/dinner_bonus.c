/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:46:58 by francfer          #+#    #+#             */
/*   Updated: 2024/05/12 21:03:59 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo_bonus.h"

void	*routine(t_philo	*ph)
{
	while (1)
	{
		take_fork(ph);
		sem_post(ph->table->sem_forks);
		sem_post(ph->table->sem_forks);
		message(ph->table, ph->philo_id, SLEEPING);
		ft_usleep(ph->table->time_to_sleep);
		message(ph->table, ph->philo_id, THINKING);
		usleep(100);
	}
	return (NULL);
}

void	take_fork(t_philo *philo)
{
	sem_wait(philo->table->sem_forks);
	message(philo->table, philo->philo_id, TAKE_FIRST_FORK);
	sem_wait(philo->table->sem_forks);
	message(philo->table, philo->philo_id, TAKE_SECOND_FORK);
	message(philo->table, philo->philo_id, EATING);
	sem_wait(philo->sem_eat);
	sem_post(philo->table->sem_meal);
	philo->last_meal_time = get_time();
	ft_usleep(philo->table->time_to_eat);
	sem_post(philo->sem_eat);
}

void	start_philo(t_table	*table)
{
	int	i;

	i = 0;
	if (table->meal_amount)
		pthread_create(&table->monitor_meal, NULL, monitor_meal,
			(void *)table);
	while (i < table->philo_amount)
	{
		table->philos[i]->philo_pid = fork();
		table->philos[i]->last_meal_time = get_time();
		if (table->philos[i]->philo_pid == 0)
		{
			pthread_create(&table->philos[i]->monitor_die, NULL, monitor_die,
				(void *)table->philos[i]);
			routine(table->philos[i]);
			exit(1);
		}
		i++;
		usleep(100);
	}
	close_processes(table);
}
