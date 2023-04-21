/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:37:20 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 11:41:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_get_state.h"

#include <pthread.h>

#include "table.h"

t_e_game_state	table_get_state(void)
{
	t_s_table		*table;
	t_e_game_state	state;

	table = table_get();
	pthread_mutex_lock(&table->lock_state);
	state = table->game_state;
	pthread_mutex_unlock(&table->lock_state);
	return (state);
}
