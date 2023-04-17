/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_request.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:28:12 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 17:30:46 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_request.h"

#include <limits.h>

#include "table.h"
#include "table_get_left.h"
#include "table_get_right.h"

bool	table_request(t_s_philo *philo)
{
	t_s_table	*table;
	t_s_philo	*neighbour_left;
	t_s_philo	*neighbour_right;

	if (philo == NULL)
		return (false);
	table = table_get();
	pthread_mutex_lock(table->lock_request);
	neighbour_left = table_get_left(table, philo->id);
	neighbour_right = tables_get_right(table, philo->id);
	if (neighbour_left->time_last_meal < philo->time_last_meal)
		return ((void)pthread_mutex_unlock(table->lock_request), false);
	if (neighbour_right->time_last_meal < philo->time_last_meal)
		return ((void)pthread_mutex_unlock(table->lock_request), false);
	pthread_mutex_unlock(table->lock_request);
	return (true);
}
