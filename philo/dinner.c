/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:19:44 by francfer          #+#    #+#             */
/*   Updated: 2024/04/02 16:23:29 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	thinking(t_philo *philo)
{
	write_status(THINKING, philo);
}

static void	eat(t_philo *philo)
{
	safe_mutex_handler(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo);
	safe_mutex_handler(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILISECOND));
	philo->meals_counter++;
	write_status(EATING, philo);
	precise_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->limits_of_meals > 0
		&& philo->meals_counter == philo->table->limits_of_meals)
		set_int(&philo->philo_mutex, &philo->full, 1);
	safe_mutex_handler(&philo->first_fork->fork, UNLOCK);
	safe_mutex_handler(&philo->second_fork->fork, UNLOCK);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	while (!simulation_finished(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		precise_usleep(philo->table->time_to_sleep, philo->table);
		thinking(philo);
	}
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if (table->limits_of_meals == 0)
		return ;
	else if (table->philo_numbers == 1)
		;
	else
	{
		while (++i < table->philo_numbers)
			safe_thread_handler(&table->philos[i].philo_thread_id,
				dinner_simulation, &table->philos[i], CREATE);
	}
	table->start_simulation = get_time(MILISECOND);
	set_int(&table->table_mutex, &table->all_threads_ready, 1);
	i = -1;
	while (++i < table->philo_numbers)
		safe_thread_handler(&table->philos[i].philo_thread_id, NULL, NULL,
			JOIN);
}
