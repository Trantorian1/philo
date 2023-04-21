/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:46:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 15:59:24 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_get_time.h"

#include <pthread.h>

#include "table.h"

int64_t	table_get_time(void)
{
	t_s_table	*table;
	int64_t		time;

	table = table_get();
	pthread_mutex_lock(&table->lock_time);
	time = table->time_curr;
	pthread_mutex_unlock(&table->lock_time);
	return (time);
}
