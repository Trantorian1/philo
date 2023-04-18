/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:06:09 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/18 10:59:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_get_right.h"

t_s_philo	*tables_get_right(t_s_table *table, int32_t seat)
{
	if (table == NULL || seat >= table->size)
		return (NULL);
	if (seat == table->size - 1)
		return (&table->guests[0]);
	return (&table->guests[seat + 1]);
}
