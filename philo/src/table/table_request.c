/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_request.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:28:12 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 11:36:48 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_request.h"

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#include "e_philo_state.h"
#include "philo_set_ownership.h"
#include "philo_get_state.h"
#include "table.h"
#include "table_get_left.h"
#include "table_get_right.h"

static bool	has_priority(t_s_philo *philo, t_s_philo *neighbour)
{
	bool	priority_meals;
	bool	priority_owner;
	int64_t	bias;

	if (neighbour == philo)
		return (true);
	pthread_mutex_lock(&neighbour->lock_attr);
	bias = table_get()->args->time_eat;
	priority_meals = neighbour->time_last_meal + bias < philo->time_last_meal;
	priority_owner = neighbour->ownership == true;
	pthread_mutex_unlock(&neighbour->lock_attr);
	return (priority_meals || priority_owner);
}

bool	table_request(t_s_philo *philo)
{
	t_s_table	*table;
	t_s_philo	*neighbour_left;
	t_s_philo	*neighbour_right;

	if (philo == NULL)
		return (false);
	table = table_get();
	neighbour_left = table_get_left(table, philo->id);
	neighbour_right = tables_get_right(table, philo->id);
	if (has_priority(philo, neighbour_left))
		return (false);
	if (has_priority(philo, neighbour_right))
		return (false);
	philo_set_ownership(philo, true);
	return (true);
}
