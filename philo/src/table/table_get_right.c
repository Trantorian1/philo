/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:06:09 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 11:52:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_get_right.h"

t_s_philo	*table_get_right(t_s_table *table, int32_t seat)
{
	if (table == NULL || seat >= table->size)
		return (NULL);
	if (seat == table->size - 1)
		return (table->guests);
	return (table->guests + seat + 1);
}
