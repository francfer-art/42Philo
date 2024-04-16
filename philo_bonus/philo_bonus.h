/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:05:04 by francfer          #+#    #+#             */
/*   Updated: 2024/04/16 16:16:58 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>

typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					id;
}						t_fork;

typedef struct s_table
{
	long				philo_numbers;
	long				time_to_eat;
	long				time_to_die;
	long				time_to_sleep;
	long				limits_of_meals;
	long				start_simulation;
	int					end_simulation;
	int					all_threads_ready;
	long				threads_number_running;
	pthread_t			monitor;
	pthread_mutex_t		table_mutex;
	pthread_mutex_t		write_mutex;
	t_philo				*philos;
	t_fork				*forks;
}						t_table;

typedef struct s_philo
{
	int					id;
	int					full;
	long				meals_counter;
	long				last_meal_time;
	pthread_t			philo_thread_id;
	pthread_mutex_t		philo_mutex;
	t_fork				*second_fork;
	t_fork				*first_fork;
	t_table				*table;
}						t_philo;

//utils_bonus.c
int		is_sign(char c);
int		is_digit(char c);
int		arg_is_number(char *str);
int		is_correct_input(int args, char **argv);
long	ft_atol(const char *str);

//parser_bonus.c
void	parsing_input(t_table *table, char **argv);

//utils1_bonus.c
void	ft_error(char *msg);

#endif