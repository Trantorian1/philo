/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:20:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 16:19:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_destroy.h"

#include <stdlib.h>

#include "philo_deinit.h"
#include "philo_destroy.h"
#include "table.h"
#include "table_join.h"

static void	destroy_guests(t_s_table *table)
{
	int32_t	index;

	index = -1;
	while (++index < table->size)
		philo_destroy(table->guests + index);
	free(table->guests);
}

static void	destroy_forks(t_s_table *table)
{
	int32_t	index;

	index = -1;
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
	if (table->guests)
		destroy_guests(table);
	if (table->forks)
		destroy_forks(table);
	if (table->init_state)
		pthread_mutex_destroy(&table->lock_state);
	if (table->init_ready)
		pthread_mutex_destroy(&table->lock_ready);
	if (table->init_time)
		pthread_mutex_destroy(&table->lock_time);
	return (NULL);
}
