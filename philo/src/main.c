/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:24:13 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 09:59:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "s_table.h"
#include "e_game_state.h"
#include "table.h"
#include "table_init.h"
#include "table_join.h"
#include "table_destroy.h"

static void	*runner(void *data)
{
	(void)data;
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_s_table	*table;

	(void)argc;
	(void)argv;
	table = table_get();
	if (table == NULL)
		return (EXIT_FAILURE);
	if (table_init((size_t)argc, &runner) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	table->game_state = SYNCHRONISED;
	table_join();
	table_destroy();
	return (EXIT_SUCCESS);
}
