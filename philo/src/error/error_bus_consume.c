/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bus_consume.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:45:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/06 18:50:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bus_consume.h"

#include <stdlib.h>

/**
 * @brief Consumes an error in an error bus.
 *
 * Since errors can potentially be thrown from multiple threads, each error is
 * counted and is only resolved once ALL error occurences have been consumed
 * (ie: handled).
 *
 * @param error_bus (t_s_error_bus *): Bus containing the error codes.
 * @param error_code (t_e_error_code): Error code to check for.
 * @return (bool): true if all errors code occurences have been consumed, false
 * otherwise.
 */
bool	error_bus_consume(t_s_error_bus *error_bus, t_e_error_code error_code)
{
	if (error_bus == NULL || error_code == E_ERRORS_SIZE)
		return (false);
	if (error_bus->errors[error_code] > 0)
		error_bus->errors[error_code]--;
	if (error_bus->errors[error_code] == 0)
		return (true);
	return (false);
}
