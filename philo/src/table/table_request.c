/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_request.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:28:12 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/18 09:54:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_request.h"

#include <limits.h>

#include "table.h"
#include "table_get_left.h"
#include "table_get_right.h"

static bool	has_priority(t_s_philo *philo, t_s_philo *neighbour)
{
	bool	priority_meals;
	bool	priority_owner;

	pthread_mutex_lock(&neighbour->lock_attr);
	priority_meals = neighbour->time_last_meal >= philo->time_last_meal;
	priority_owner = neighbour->owner == false;
	pthread_mutex_unlock(&neighbour->lock_attr);
	return (priority_meals && priority_owner);
}

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
	if (!has_priority(philo, neighbour_left))
		return ((void)pthread_mutex_unlock(table->lock_request), false);
	if (!has_priority(philo, neighbour_right))
		return ((void)pthread_mutex_unlock(table->lock_request), false);
	philo->owner = true;
	pthread_mutex_unlock(table->lock_request);
	return (true);
}
