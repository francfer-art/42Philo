/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:58:31 by francfer          #+#    #+#             */
/*   Updated: 2024/05/12 20:36:03 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo_bonus.h"

t_philo	**philo_init(t_table *table)
{
	t_philo	**philo;
	int		i;

	philo = (t_philo **)malloc(sizeof(t_philo *) * table->philo_amount);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < table->philo_amount)
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo) * 1);
		if (!philo[i])
			return (0);
		philo[i]->philo_id = i + 1;
		philo[i]->table = table;
		sem_unlink("eatcounter");
		philo[i]->sem_eat = sem_open("eatcounter", O_CREAT, 0644, 1);
		if (philo[i]->sem_eat == SEM_FAILED)
			return (NULL);
		i++;
	}
	return (philo);
}

int	semaphores_init(t_table *table)
{
	sem_unlink("forking");
	table->sem_forks = sem_open("forking", O_CREAT, 0644,
			table->philo_amount);
	if (table->sem_forks == SEM_FAILED)
		return (1);
	sem_unlink("writing");
	table->sem_write = sem_open("writing", O_CREAT, 0644, 1);
	if (table->sem_write == SEM_FAILED)
		return (1);
	sem_unlink("meal");
	table->sem_meal = sem_open("meal", O_CREAT, 0644, 1);
	if (table->sem_meal == SEM_FAILED)
		return (1);
	return (0);
}

t_table	*init(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	if (!table)
		return (NULL);
	table->philo_amount = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (table->philo_amount <= 0 || table->time_to_die <= 0
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0)
		return (printf("Error: Invalid Arguments\n"), NULL);
	table->meal_amount = 0;
	if (argc == 6)
		table->meal_amount = ft_atol(argv[5]);
	if (semaphores_init(table))
		return (NULL);
	table->start_time = get_time();
	table->philos = philo_init(table);
	return (table);
}
