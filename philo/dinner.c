/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:19:44 by francfer          #+#    #+#             */
/*   Updated: 2024/04/07 20:44:18 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void	thinking(t_philo *philo, int pre_simulation)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!pre_simulation)
		write_status(THINKING, philo);
	if (philo->table->philo_numbers % 2 == 0)
		return ;
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	precise_usleep(t_think * 0.42, philo->table);
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

void	*lone_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILISECOND));
	increase_long(&philo->table->table_mutex, &philo->table->threads_number_running);
	write_status(TAKE_FIRST_FORK, philo);
	while (!simulation_finished(philo->table))
		precise_usleep(200, philo->table);
	return (NULL);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILISECOND));
	increase_long(&philo->table->table_mutex, &philo->table->threads_number_running);
	de_synchro_philos(philo);
	while (!simulation_finished(philo->table))
	{
		if (get_int(&philo->philo_mutex, &philo->full))
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		precise_usleep(philo->table->time_to_sleep, philo->table);
		thinking(philo, 0);
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
		safe_thread_handler(&table->philos[0].philo_thread_id, lone_philo, &table->philos[0], CREATE);
	else
	{
		while (++i < table->philo_numbers)
			safe_thread_handler(&table->philos[i].philo_thread_id,
				dinner_simulation, &table->philos[i], CREATE);
	}
	safe_thread_handler(&table->monitor, monitor_dinner, table, CREATE);
	table->start_simulation = get_time(MILISECOND);
	set_int(&table->table_mutex, &table->all_threads_ready, 1);
	i = -1;
	while (++i < table->philo_numbers)
		safe_thread_handler(&table->philos[i].philo_thread_id, NULL, NULL,
			JOIN);
	set_int(&table->table_mutex, &table->end_simulation, 1);
	safe_thread_handler(&table->monitor, NULL, NULL, JOIN);
}
