/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:47:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/13 11:13:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_join.h"

#include <pthread.h>
#include <stddef.h>

#include "s_table.h"
#include "table.h"

void	table_join(void)
{
	t_s_table	*table;
	int32_t		index;

	table = table_get();
	index = -1;
	while (++index < table->size)
		pthread_join(table->guests[index].thread, NULL);
}
