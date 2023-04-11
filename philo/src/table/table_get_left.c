/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:01:20 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 17:55:31 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_get_left.h"

t_s_philo	*table_get_left(t_s_table *table, size_t seat)
{
	if (table == NULL || seat >= table->size)
		return (NULL);
	if (seat == 0)
		return (&table->guests[table->size - 1]);
	return (&table->guests[seat - 1]);
}
