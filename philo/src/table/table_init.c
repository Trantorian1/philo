/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:36:45 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/12 10:44:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_init.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "e_game_state.h"
#include "e_philo_state.h"
#include "philo_deinit.h"
#include "philo_init.h"
#include "table_destroy.h"
#include "table_get_left.h"
#include "table.h"

static int32_t	init_guests(t_s_table *table, t_f_runner runner)
{
	size_t		index;
	int32_t		error_code;

	if (table == NULL || runner == NULL)
		return (EXIT_FAILURE);
	table->guests = malloc(sizeof(*table->guests));
	if (table->guests == NULL)
		return (EXIT_FAILURE);
	index = (size_t)(-1);
	while (++index < table->size)
	{
		error_code = philo_init(&table->guests[index], index, runner);
		if (error_code == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int32_t	deinit_cuttlery(t_s_table *table, size_t target)
{
	size_t	index;

	if (table == NULL || target >= table->size)
		return (EXIT_FAILURE);
	index = (size_t)(-1);
	while (++index < target)
		pthread_mutex_destroy(&table->forks[index]);
	return (EXIT_FAILURE);
}

static int32_t	init_cuttlery(t_s_table *table)
{
	size_t	index;

	if (table == NULL)
		return (EXIT_FAILURE);
	table->forks = malloc(table->size * sizeof(*table->forks));
	if (table->forks == NULL)
		return (EXIT_FAILURE);
	index = (size_t)(-1);
	while (++index < table->size)
		if (pthread_mutex_init(&table->forks[index], NULL) != EXIT_SUCCESS)
			return (deinit_cuttlery(table, index));
	return (EXIT_SUCCESS);
}

static void	distribute_cuttlery(t_s_table *table)
{
	size_t		index;
	t_s_philo	*guest_left;
	t_s_philo	*guest_curr;

	index = (size_t)(-1);
	while (++index < table->size)
	{
		guest_left = table_get_left(table, index);
		guest_curr = &table->guests[index];
		guest_left->fork_right = table->forks[index];
		guest_curr->fork_left = table->forks[index];
	}
}

int32_t	table_init(size_t size, t_f_runner runner)
{
	t_s_table	*table;

	table = table_get();
	if (table == NULL)
		return (EXIT_FAILURE);
	table->game_state = IDLE;
	table->size = size;
	if (init_guests(table, runner) == EXIT_FAILURE)
		return ((void)table_destroy(), EXIT_FAILURE);
	if (init_cuttlery(table) == EXIT_FAILURE)
		return ((void)table_destroy(), EXIT_FAILURE);
	distribute_cuttlery(table);
	return (EXIT_SUCCESS);
}
