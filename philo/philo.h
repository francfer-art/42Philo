/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:26:27 by francfer          #+#    #+#             */
/*   Updated: 2024/03/29 20:52:32 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <errno.h>

typedef enum s_code
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}	t_code;

typedef struct s_fork t_fork;
typedef struct s_philo t_philo;
typedef struct s_table t_table;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}	t_fork;

typedef struct s_table
{
	long	philo_numbers;
	long	time_to_eat;
	long	time_to_die;
	long	time_to_sleep;
	long	limits_of_meals;
	long	start_simulation;
	int		end_simulation;
	t_philo	*philos;
	t_fork	*forks;
}	t_table;

typedef struct s_philo
{
	int			id;
	int			full;
	long		meals_counter;
	long		last_meal_time;
	pthread_t	philo_thread_id;
	t_fork		*right_fork;
	t_fork		*left_fork;
	t_table		*table;
}	t_philo;

int			is_sign(char c);
int			is_digit(char c);
int			arg_is_number(char *str);
int			is_correct_input(int args, char **argv);
long		ft_atol(const char *str);
void		parsing_input(t_table *table, char **argv);
void		ft_error(char	*error_message);

void    *safe_malloc(size_t bytes);

void    data_init(t_table *table);
void    safe_mutex_handler(pthread_mutex_t *mutex, t_code code);
void    safe_thread_handler(pthread_t *thread, void *(*foo)(void *), void *data, t_code code);

#endif