/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:26:27 by francfer          #+#    #+#             */
/*   Updated: 2024/04/15 16:04:40 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum s_state
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED
}						t_state;

typedef enum s_code
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}						t_code;

typedef enum s_time_code
{
	SECOND,
	MILISECOND,
	MICROSECOND
}						t_time_code;

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

//utils.c
int						is_sign(char c);
int						is_digit(char c);
int						arg_is_number(char *str);
int						is_correct_input(int args, char **argv);
long					ft_atol(const char *str);

//parser.c
void					parsing_input(t_table *table, char **argv);

//utils1.c
void					ft_error(char *error_message);
long					get_time(t_time_code time);
void					precise_usleep(long time, t_table *table);
void					clean(t_table *table);

//init.c
void					data_init(t_table *table);

//safe_functions.c
void					*safe_malloc(size_t bytes);
void					safe_mutex_handler(pthread_mutex_t *mutex, t_code code);
void					safe_thread_handler(pthread_t *thread,
							void *(*foo)(void *), void *data, t_code code);

//get_set.c
void					set_int(pthread_mutex_t *mutex, int *dest, int value);
int						get_int(pthread_mutex_t *mutex, int *value);
long					get_long(pthread_mutex_t *mutex, long *value);
void					set_long(pthread_mutex_t *mutex, long *dest,
							long value);
int						simulation_finished(t_table *table);

//write.c
void					write_status(t_state code, t_philo *philo);

//dinner.c
void					dinner_start(t_table *table);
void					thinking(t_philo *philo, int pre_simulation);
void					*lone_philo(void *arg);

//synchro_utils.c
void					wait_all_threads(t_table *table);
void					increase_long(pthread_mutex_t *mutex, long *thread);
int						all_threads_running(pthread_mutex_t *mutex,
							long *threads, long philo_nbr);
void					de_synchronize_philos(t_philo *philo);

//monitoring.c
void					*monitor_dinner(void *data);

#endif