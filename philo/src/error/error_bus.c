/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:52:34 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 10:00:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bus.h"

#include <pthread.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Singleton error bus instance.
 *
 * @return (t_s_error_bus *): error bus singleton.
 */
t_s_error_bus	*error_bus(void)
{
	static t_s_error_bus	*bus = NULL;

	if (bus != NULL)
		return (bus);
	bus = malloc(sizeof(*bus));
	if (bus == NULL)
		return (NULL);
	memset(bus->errors, 0, E_ERRORS_SIZE);
	if (pthread_mutex_init(&bus->lock, NULL) != EXIT_SUCCESS)
		return ((void)free(bus), NULL);
	return (bus);
}
