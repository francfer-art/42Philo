/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:37:10 by francfer          #+#    #+#             */
/*   Updated: 2024/03/31 18:48:48 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

static void assign_forks(t_philo *philo, t_fork *forks, int i)
{
    philo->second_fork = &forks[i];
    philo->first_fork = &forks[(i + 1) % philo->table->philo_numbers];
    if (philo->id % 2 == 0)
    {
        philo->first_fork = &forks[i];
        philo->second_fork = &forks[(i + 1) % philo->table->philo_numbers];
    }
}

static void philo_init(t_table *table)
{
    int     i;
    t_philo *philo;

    i = 0;
    while (i < table->philo_numbers)
    {
        philo = table->philos + i;
        philo->id = i + 1;
        philo->full = 0;
        philo->meals_counter = 0;
        philo->table = table;
        safe_mutex_handler(&philo->philo_mutex, INIT);
        assign_forks(philo, table->forks, i);
        i++;
    }
}

void    data_init(t_table *table)
{
    int i;

    i = 0;
    table->end_simulation = 0;
    table->all_threads_ready = 0;
    table->philos = safe_malloc(sizeof(t_philo) * table->philo_numbers);
    safe_mutex_handler(&table->table_mutex, INIT);
    safe_mutex_handler(&table->write_mutex, INIT);
    table->forks = safe_malloc(sizeof(t_fork) * table->philo_numbers);
    while (i < table->philo_numbers)
    {
        safe_mutex_handler(&table->forks[i].fork, INIT);
        table->forks[i].id = i;
        i++;
    }
    philo_init(table);
}
