/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:20:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 14:24:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_destroy.h"

#include <stdlib.h>

#include "philo_deinit.h"
#include "table.h"
#include "table_join.h"

static void	destroy_lock(pthread_mutex_t *lock)
{
	pthread_mutex_destroy(lock);
	free(lock);
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
	table_join();
	if (table->lock_request)
		destroy_lock(table->lock_request);
	if (table->lock_state)
		destroy_lock(table->lock_state);
	if (table->guests)
		free(table->guests);
	if (table->forks)
		destroy_forks(table);
	return (NULL);
}
