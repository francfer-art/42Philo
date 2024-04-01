/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:55:46 by francfer          #+#    #+#             */
/*   Updated: 2024/03/31 19:38:23 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void	ft_error(char	*error_message)
{
	printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}

long	get_time(t_time_code time)
{
	struct	timeval tv;

	if (gettimeofday(&tv, NULL))
		ft_error("Gettimeofday() error!");
	if (time == SECOND)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	else if (time == MILISECOND)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	else if (time == MICROSECOND)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		ft_error("Wrong time code!");
	return (42);
}

void	precise_usleep(long time, t_table *table)
{
	long	start;
	long	elapsed;
	long	rem;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < time)
	{
		if (simulation_finished(table))
			break ;
		elapsed = get_time(MICROSECOND) - start;
		rem = time - elapsed;
		if (rem > 1e4)
			usleep(rem / 2);
		else
			while (get_time(MICROSECOND) - start < time)
				;
	}
}

void	clean(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < table->philo_numbers)
	{
		philo = table->philos + i;
		safe_mutex_handler(&philo->philo_mutex, DESTROY);
	}
	safe_mutex_handler(&table->table_mutex, DESTROY);
	safe_mutex_handler(&table->write_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}