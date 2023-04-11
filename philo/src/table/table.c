/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:27:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 18:30:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

#include <stdlib.h>

t_s_table	*table_get(void)
{
	static t_s_table	*table = NULL;

	if (table != NULL)
		return (table);
	table = malloc(sizeof(*table));
	return (table);
}
