/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bus_consume.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:45:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 10:05:08 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bus_consume.h"

#include <pthread.h>
#include <stdlib.h>

#include "error_bus.h"
#include "s_error_bus.h"

/**
 * @brief Consumes an error in an error bus.
 *
 * Since errors can potentially be thrown from multiple threads, each error is
 * counted and is only resolved once ALL error occurences have been consumed
 * (ie: handled).
 *
 * @param error_code (t_e_error_code): Error code to check for.
 * @return (bool): true if all errors code occurences have been consumed, false
 * otherwise.
 */
bool	error_bus_consume(t_e_error_code error_code)
{
	t_s_error_bus	*bus;
	bool			has_error;

	bus = error_bus();
	has_error = false;
	if (bus == NULL || error_code == E_ERRORS_SIZE)
		return (false);
	pthread_mutex_lock(&bus->lock);
	if (bus->errors[error_code] > 0)
		bus->errors[error_code]--;
	if (bus->errors[error_code] == 0)
		has_error = true;
	pthread_mutex_unlock(&bus->lock);
	return (has_error);
}
