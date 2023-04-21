/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_set_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:26:26 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 11:41:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_set_state.h"

#include <pthread.h>
#include <stdlib.h>

#include "table.h"

int32_t	table_set_state(t_e_game_state state)
{
	t_s_table	*table;

	table = table_get();
	pthread_mutex_lock(&table->lock_state);
	table->game_state = state;
	pthread_mutex_unlock(&table->lock_state);
	return (EXIT_SUCCESS);
}
