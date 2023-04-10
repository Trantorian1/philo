/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bus_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:35:57 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 09:44:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bus_set.h"

#include "error_bus.h"

#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

void	error_bus_set(t_e_error_code error_code)
{
	t_s_error_bus	*bus;
	bool			inval_code;

	bus = error_bus();
	inval_code = ((error_code == E_ERRORS_SIZE) || (error_code == ERROR_NONE));
	if (bus == NULL || inval_code)
		return ;
	pthread_mutex_lock(&bus->lock);
	bus->errors[error_code]++;
	pthread_mutex_unlock(&bus->lock);
}
