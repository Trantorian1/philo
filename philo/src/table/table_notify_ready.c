/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_notify_ready.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:31:16 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 14:37:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_notify_ready.h"

#include "table.h"

void	table_notify_ready(void)
{
	t_s_table	*table;

	table = table_get();
	pthread_mutex_lock(&table->lock_ready);
	table->ready++;
	pthread_mutex_unlock(&table->lock_ready);
}
