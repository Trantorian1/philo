/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:12:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 14:59:52 by emcnab           ###   ########.fr       */
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
#include "s_table.h"
#include "table.h"
#include "table_set_state.h"

int32_t	table_loop(void)
{
	t_s_table		*table;
	int32_t			index;
	t_e_philo_state	state;

	table = table_get();
	index = -1;
	while (true)
	{
		while (++index < table->size)
		{
			state = philo_get_state(&table->guests[index]);
			if (state == STATE_DEAD || state == STATE_DEAD)
			{
				table_set_state(END);
				return (EXIT_SUCCESS);
			}
		}
		message_bus_flush();
	}
	return (EXIT_FAILURE);
}
