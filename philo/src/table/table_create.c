/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:36:45 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 15:20:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_create.h"

#include <stdlib.h>

#include "e_philo_state.h"
#include "philo_create.h"

static void	*init_philos(t_s_table *table, t_f_runner runner)
{
	size_t	index;

	index = (size_t)(-1);
	while (++index < table->size)
		table->guests[index] = philo_create(
				&table->guests[index],
				motinor_get_forks(),
				runner);
}

t_s_table	*table_create(size_t size, t_f_runner runner)
{
	t_s_table	*table;

	table = malloc(sizeof(*table));
	if (table == NULL)
		return (NULL);
	table->size = size;
	table->guests = malloc(sizeof(*table->guests));
	if (init_philos(table, runner) == NULL)
		return (table_destroy(table));
	return (table);
}
