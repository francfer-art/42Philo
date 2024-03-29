/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:40:25 by francfer          #+#    #+#             */
/*   Updated: 2024/03/29 12:44:21 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void    *safe_malloc(size_t bytes)
{
    void    *ret;

    ret = malloc(bytes);
    if (!ret)
        ft_error("Error allocating memory!");
    return (ret);
}