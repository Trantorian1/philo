/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_is_ready.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:38:35 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 14:40:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_is_ready.h"

#include "table.h"

bool	table_is_ready(void)
{
	t_s_table	*table;
	bool		ready;

	table = table_get();
	pthread_mutex_lock(&table->lock_ready);
	ready = table->ready == table->size;
	pthread_mutex_unlock(&table->lock_ready);
	return (ready);
}
