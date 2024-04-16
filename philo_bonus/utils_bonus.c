/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:17:23 by francfer          #+#    #+#             */
/*   Updated: 2024/04/16 12:08:06 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	arg_is_number(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i] && str[i + 1]))
		i++;
	while (str[i] && is_digit(str[i]))
		i++;
	if (str[i] && !is_digit(str[i]))
		return (0);
	return (1);
}

int	is_correct_input(int args, char **argv)
{
	int	i;

	i = 1;
	if ((args != 5) && (args != 6))
		return (0);
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i])
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}
