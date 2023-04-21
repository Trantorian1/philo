/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:12:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 15:59:54 by emcnab           ###   ########.fr       */
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

int32_t	table_loop(void)
{
	t_s_table		*table;
	int32_t			index;
	int32_t			satiated;
	t_e_philo_state	state;

	table = table_get();
	while (true)
	{
		index = -1;
		satiated = 0;
		while (++index < table->size)
		{
			pthread_mutex_lock(&table->lock_time);
			if (time_millis(&table->time_curr) != EXIT_SUCCESS)
				return (table_loop_exit());
			pthread_mutex_unlock(&table->lock_time);
			state = philo_get_state(&table->guests[index]);
			if (state == STATE_DEAD || state == STATE_DEAD)
				return (table_loop_exit());
			if (philo_get_meals(&table->guests[index]) >= table->args->meal_target)
				satiated++;
		}
		if (satiated == table->size)
			return (table_loop_exit());
		message_bus_flush();
	}
	return (EXIT_FAILURE);
}
