/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:24:13 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 19:02:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "e_philo_state.h"
#include "s_table.h"
#include "s_message_bus.h"
#include "e_game_state.h"
#include "table.h"
#include "table_init.h"
#include "table_destroy.h"
#include "message_bus_send.h"

static void	*runner(void *data)
{
	t_s_philo		*philo;
	t_s_message_bus	*message_bus;

	philo = (t_s_philo *)data;
	message_bus_send(philo->id, philo->state);
	return (NULL);
}

static void	end_simulation(t_s_table *table)
{
	table->game_state = END;
	table_destroy();
}

// WARNING: remember to call message_bus_flush once all threas have been joined
int	main(int argc, char **argv)
{
	t_s_table	*table;

	(void)argc;
	(void)argv;
	table = table_get();
	if (table == NULL)
		return (EXIT_FAILURE);
	if (table_init((size_t)(argc - 1), &runner) == EXIT_FAILURE)
		return ((void)end_simulation(table), EXIT_FAILURE);
	table->game_state = SYNCHRONISED;
	end_simulation(table);
	return (EXIT_SUCCESS);
}
