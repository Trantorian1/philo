/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:20:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 10:42:18 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_destroy.h"

#include <stdlib.h>

#include "error_bus_destroy.h"
#include "philo_deinit.h"
#include "table.h"
#include "table_join.h"

static void	destroy_forks(t_s_table *table)
{
	size_t	index;

	index = (size_t)(-1);
	while (++index < table->size)
		pthread_mutex_destroy(&table->forks[index]);
	free(table->forks);
}

void	*table_destroy(void)
{
	t_s_table	*table;

	table = table_get();
	if (table == NULL)
		return (NULL);
	table_join();
	if (table->guests)
		free(table->guests);
	if (table->forks)
		destroy_forks(table);
	error_bus_destroy();
	free(table);
	return (NULL);
}
