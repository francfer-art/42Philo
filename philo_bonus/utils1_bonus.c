/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:13:11 by francfer          #+#    #+#             */
/*   Updated: 2024/04/24 18:27:28 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	message(t_table *table, int philo_number, t_state msg)
{
	sem_wait(table->sem_write);
	if (msg == EATING)
		printf("%d %d is eating\n", get_time() - table->start_time,
			philo_number);
	else if (msg == DIED)
		printf("\033[0;31m%d %d died\n\033[0m", get_time() - table->start_time,
			philo_number);
	else if (msg == TAKE_FIRST_FORK || msg == TAKE_SECOND_FORK)
		printf("%d %d has taken a fork\n", get_time() - table->start_time,
			philo_number);
	else if (msg == THINKING)
		printf("%d %d thinking\n", get_time() - table->start_time,
			philo_number);
	else if (msg == SLEEPING)
		printf("%d %d sleeping\n", get_time() - table->start_time,
			philo_number);
	if (msg != DIED)
		sem_post(table->sem_write);
}

void	close_processes(t_table *table)
{
	int		i;
	int		status;
	pid_t	pids[1024];

	i = -1;
	waitpid(-1, &status, 0);
	if (WIFEXITED(status) || WIFSIGNALED(status))
	{
		while (++i < table->philo_amount)
		{
			pids[i] = table->philos[i]->philo_pid;
			free(table->philos[i]);
			kill(pids[i], SIGKILL);
		}
	}
	free(table->philos);
	free(table);
}

void	ft_usleep(int time_in_ms)
{
	int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
