/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:27:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 17:07:16 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

#include <stdlib.h>

/**
 * @brief Singleton table monitor.
 *
 * Singleton instance of a table for use as a thread monitor in Dijkstra's
 * dining philosophers problem.
 *
 * @return (t_s_table *): Singleton table instance.
 */
t_s_table	*table_get(void)
{
	static t_s_table	table = {.size = 0};

	return (&table);
}
