/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bus_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:35:57 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/06 18:43:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bus_set.h"

#include <stdlib.h>
#include <stdbool.h>

void	error_bus_set(t_s_error_bus *error_bus, t_e_error_code error_code)
{
	bool	code_inv;

	code_inv = ((error_code == E_ERRORS_SIZE) || (error_code == ERROR_NONE));
	if (error_bus == NULL || code_inv)
		return ;
	error_bus->errors[error_code]++;
}
