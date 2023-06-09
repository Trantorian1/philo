/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:36:45 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 16:10:09 by emcnab           ###   ########.fr       */
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
#include "table_get_right.h"
#include "table.h"
#include "libft.h"

static int32_t	init_guests(t_s_table *table, t_f_runner runner)
{
	int32_t	index;
	int32_t	error_code;

	table->guests = malloc((size_t)table->size * sizeof(*table->guests));
	if (table->guests == NULL)
		return (EXIT_FAILURE);
	index = -1;
	while (++index < table->size)
	{
		error_code = philo_init(&table->guests[index], index, runner);
		if (error_code == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	index = -1;
	while (++index < table->size)
	{
		table->guests[index].neighbour_left = table_get_left(table, index);
		table->guests[index].neighbour_right = table_get_right(table, index);
	}
	return (EXIT_SUCCESS);
}

static int32_t	init_cuttlery(t_s_table *table)
{
	int32_t	index;

	table->forks = malloc((size_t)table->size * sizeof(*table->forks));
	if (table->forks == NULL)
		return (EXIT_FAILURE);
	index = -1;
	while (++index < table->size)
	{
		if (pthread_mutex_init(&table->forks[index], NULL) != EXIT_SUCCESS)
		{
			while (--index >= 0)
				pthread_mutex_destroy(&table->forks[index]);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static void	distribute_cuttlery(t_s_table *table)
{
	int32_t		index;
	t_s_philo	*guest_left;
	t_s_philo	*guest_curr;

	index = -1;
	while (++index < table->size)
	{
		guest_left = table_get_left(table, index);
		guest_curr = &table->guests[index];
		guest_left->fork_right = table->forks[index];
		guest_curr->fork_left = table->forks[index];
	}
}

// TODO: add flags so destructor knows wether or not mutexes were initialised
static int32_t	init_locks(t_s_table *table)
{
	if (pthread_mutex_init(&table->lock_state, NULL) != EXIT_SUCCESS)
		return ((void)table_destroy(), EXIT_FAILURE);
	table->init_state = true;
	if (pthread_mutex_init(&table->lock_ready, NULL) != EXIT_SUCCESS)
		return ((void)table_destroy(), EXIT_FAILURE);
	table->init_ready = true;
	if (pthread_mutex_init(&table->lock_time, NULL) != EXIT_SUCCESS)
		return ((void)table_destroy(), EXIT_FAILURE);
	table->init_time = true;
	table->ready = 0;
	return (EXIT_SUCCESS);
}

int32_t	table_init(t_s_args *args, t_f_runner runner)
{
	t_s_table	*table;

	table = table_get();
	if (table == NULL)
		return (EXIT_FAILURE);
	table->game_state = IDLE;
	table->size = args->philo_count;
	table->args = args;
	table->time_start = 0;
	table->time_curr = 0;
	if (init_locks(table) == EXIT_FAILURE)
		return ((void)table_destroy(), EXIT_FAILURE);
	if (init_guests(table, runner) == EXIT_FAILURE)
		return ((void)table_destroy(), EXIT_FAILURE);
	if (init_cuttlery(table) == EXIT_FAILURE)
		return ((void)table_destroy(), EXIT_FAILURE);
	distribute_cuttlery(table);
	return (EXIT_SUCCESS);
}
