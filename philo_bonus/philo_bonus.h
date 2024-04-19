/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:41:19 by francfer          #+#    #+#             */
/*   Updated: 2024/04/19 16:11:42 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

typedef struct s_philo
{
	pid_t				philo_pid;
	pthread_t			monitor_die;
	int					philo_id;
	int					last_meal_time;
	sem_t				*sem_eat;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	int					philo_amount;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					start_time;
	int					meal_amount;
	sem_t				*sem_write;
	sem_t				*sem_meal;
	sem_t				*sem_forks;
	t_philo				**philos;
	pthread_t			monitor_meal;
}						t_table;

//utils_bonus.c
int						is_sign(char c);
int						is_digit(char c);
int						arg_is_number(char *str);
int						is_correct_input(int args, char **argv);
long					ft_atol(const char *str);

//init_bonus.c
t_table					*init(int args, char **argv);
int						semaphores_init(t_table *table);

#endif