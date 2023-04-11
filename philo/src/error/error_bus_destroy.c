/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bus_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:00:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 10:01:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bus_destroy.h"

#include <stdlib.h>

#include "error_bus.h"

/**
 * @brief Destroys the error bus.
 *
 * @return (void *): NULL
 */
void	*error_bus_destroy(void)
{
	t_s_error_bus	*bus;

	bus = error_bus();
	if (bus == NULL)
		return (NULL);
	pthread_mutex_destroy(&bus->lock);
	free(bus);
	return (NULL);
}
