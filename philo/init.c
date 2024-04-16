/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:37:10 by francfer          #+#    #+#             */
/*   Updated: 2024/04/15 12:19:02 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_fork *forks,
		int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_numbers;
	philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_numbers)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = 0;
		philo->meals_counter = 0;
		safe_mutex_handler(&philo->philo_mutex, INIT);
		philo->table = table;
		assign_forks(philo, table->forks, i);
	}
}

void	data_init(t_table *table)
{
	int		i;

	i = -1;
	table->end_simulation = 0;
	table->all_threads_ready = 0;
	table->threads_number_running = 0;
	table->philos = safe_malloc(table->philo_numbers * sizeof(t_philo));
	table->forks = safe_malloc(table->philo_numbers * sizeof(t_fork));
	safe_mutex_handler(&table->write_mutex, INIT);
	safe_mutex_handler(&table->table_mutex, INIT);
	while (++i < table->philo_numbers)
	{
		safe_mutex_handler(&table->forks[i].fork, INIT);
		table->forks[i].id = i;
	}
	philo_init(table);
}
