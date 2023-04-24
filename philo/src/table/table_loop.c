/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:12:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/22 17:03:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_loop.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "e_game_state.h"
#include "e_philo_state.h"
#include "message_bus_flush.h"
#include "philo_get_state.h"
#include "philo_get_meals.h"
#include "s_table.h"
#include "table.h"
#include "table_set_state.h"
#include "time_millis.h"

static int32_t	table_loop_exit(void)
{
	table_set_state(END);
	return (EXIT_SUCCESS);
}

static int32_t	update_clock(t_s_table *table)
{
	int32_t	error_code;

	pthread_mutex_lock(&table->lock_time);
	error_code = time_millis(&table->time_curr);
	pthread_mutex_unlock(&table->lock_time);
	return (error_code);
}

static int32_t	update_state(t_s_philo *philo)
{
	t_e_philo_state	state;

	state = philo_get_state(philo);
	if (state == STATE_DEAD || state == STATE_DEAD)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int32_t	table_loop(void)
{
	t_s_table		*table;
	int32_t			index;
	int32_t			satiated;
	int32_t			philo_meals;

	table = table_get();
	while (true)
	{
		index = -1;
		satiated = 0;
		while (++index < table->size)
		{
			if (update_clock(table) != EXIT_SUCCESS)
				return (table_loop_exit());
			if (update_state(&table->guests[index]) != EXIT_SUCCESS)
				return (table_loop_exit());
			philo_meals = philo_get_meals(&table->guests[index]);
			if (philo_meals >= table->args->meal_target)
				satiated++;
		}
		if (table->args->meal_target > 0 && satiated == table->size)
			return (table_loop_exit());
		message_bus_flush();
	}
	return (EXIT_FAILURE);
}
