/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bus_has.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:43:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 10:02:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bus_has.h"

#include <stdlib.h>

#include "error_bus.h"

/**
 * @brief Determines if a certain error type occurred.
 *
 * @param error_code (t_e_error_code): Error code to check for.
 * @return (bool): true if error_code has already occurred, false otherwise.
 */
// TODO: Is mutex locking really necessary?
bool	error_bus_has(t_e_error_code error_code)
{
	t_s_error_bus	*bus;
	bool			has_error;

	bus = error_bus();
	if (bus == NULL || error_code == E_ERRORS_SIZE)
		return (false);
	pthread_mutex_lock(&bus->lock);
	has_error = bus->errors[error_code] > 0;
	pthread_mutex_unlock(&bus->lock);
	return (has_error);
}
