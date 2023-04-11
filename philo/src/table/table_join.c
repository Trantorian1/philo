/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:47:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 18:54:37 by emcnab           ###   ########.fr       */
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
	size_t		index;

	table = table_get();
	index = (size_t)(-1);
	while (++index < table->size)
		pthread_join(table->guests[index].thread, NULL);
}
