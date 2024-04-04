/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:40:25 by francfer          #+#    #+#             */
/*   Updated: 2024/04/04 11:17:35 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		ft_error("Error allocating memory!");
	return (ret);
}

static void	handle_mutex_error(int status, t_code code)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (code == LOCK || code == UNLOCK || code == DESTROY))
		ft_error("The value specified by mutex is invalid!");
	else if (status == EINVAL && (code == INIT))
		ft_error("The value specified by attr is invalid!");
	else if (status == EDEADLK)
		ft_error("Deadlock would occur if thread blocked waiting for mutex!");
	else if (status == EPERM)
		ft_error("The current thread does not hold a lock on mutex!");
	else if (status == ENOMEM)
		ft_error("The process cannot allocate enough memory to create mutex!");
	else if (status == EBUSY)
		ft_error("Mutex is locked!");
}

void	safe_mutex_handler(pthread_mutex_t *mutex, t_code code)
{
	if (code == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), code);
	else if (code == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), code);
	else if (code == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), code);
	else if (code == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex), code);
	else
		ft_error("Wrong code for mutex handler!");
}

static void	handle_thread_error(int status, t_code code)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		ft_error("Insufficient resources to create another thread!");
	else if (status == EPERM)
		ft_error("Not enough permission!");
	else if (status == EINVAL && (code == CREATE))
		ft_error("Invalid settings in attr!");
	else if (status == EINVAL && (code == JOIN || code == DETACH))
		ft_error("The value specified by thread is not joinable!");
	else if (status == ESRCH)
		ft_error("No thread could be found corresponding to that!");
	else if (status == EDEADLK)
		ft_error("A deadlock was detected!");
}

void	safe_thread_handler(pthread_t *thread, void *(*foo)(void *), void *data,
		t_code code)
{
	if (code == CREATE)
		handle_thread_error(pthread_create(thread, NULL, foo, data), code);
	else if (code == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), code);
	else if (code == DETACH)
		handle_thread_error(pthread_detach(*thread), code);
	else
		ft_error("Wrong code for thread handler!");
}
