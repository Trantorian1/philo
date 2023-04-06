/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bus_has.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:43:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/06 18:51:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bus_has.h"

#include <stdlib.h>

/**
 * @brief Determines if a certain error type occurred.
 *
 * @param error_bus (t_s_error_bus *):  Bus containing the error codes.
 * @param error_code (t_e_error_code): Error code to check for.
 * @return (bool): true if error_code has already occurred, false otherwise.
 */
bool	error_bus_has(t_s_error_bus *error_bus, t_e_error_code error_code)
{
	if (error_bus == NULL || error_code == E_ERRORS_SIZE)
		return (false);
	return (error_bus->errors[error_code] > 0);
}
