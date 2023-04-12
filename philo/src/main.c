/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:24:13 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/12 10:55:14 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "d_error_simulation.h"
#include "e_philo_state.h"
#include "error_throw.h"
#include "message_bus_flush.h"
#include "parse_args.h"
#include "s_table.h"
#include "s_message_bus.h"
#include "e_game_state.h"
#include "table.h"
#include "table_init.h"
#include "table_destroy.h"
#include "message_bus_init.h"
#include "message_bus_send.h"
#include "libft.h"
#include "table_join.h"

static void	*runner(void *data)
{
	t_s_philo		*philo;

	philo = (t_s_philo *)data;
	philo->state = STATE_THINKING;
	message_bus_send(philo->id, philo->state);
	return (NULL);
}

static void	simulation_end(t_s_table *table)
{
	table->game_state = END;
	message_bus_flush();
	table_destroy();
}

// WARNING: remember to ALLWAYS call table_init and message_bus_init
static int32_t	simulation_start(t_s_table *table, int argc)
{
	if (table_init((size_t)(argc - 1), &runner) == EXIT_FAILURE)
	{
		simulation_end(table);
		return (error_throw(ERROR_TABLE_INIT));
	}
	if (message_bus_init() == EXIT_FAILURE)
	{
		simulation_end(table);
		return (error_throw(ERROR_MESSAGE_BUS_INIT));
	}
	table->game_state = SYNCHRONISED;
	return (EXIT_SUCCESS);
}

// WARNING: remember to call message_bus_flush once all threads have been joined
// TODO: for perfomance reasons, should only call table_join once all philo
// threads have finished executing
int	main(int argc, char **argv)
{
	t_s_table	*table;

	if (parse_args(argc, argv))
		return (error_throw(ERROR_ARGS_INVALID));
	table = table_get();
	if (table == NULL)
		return (error_throw(ERROR_TABLE_GET));
	if (simulation_start(table, argc) == EXIT_FAILURE)
		return (error_throw(ERROR_SIMULATION_START));
	table_join();
	simulation_end(table);
	return (EXIT_SUCCESS);
}
