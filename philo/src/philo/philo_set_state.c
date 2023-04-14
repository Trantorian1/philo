/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:35:57 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 18:31:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_set_state.h"

#include <pthread.h>
#include <stdlib.h>

#include "message_bus_send.h"

// TODO: implement mutex protection here
int32_t	philo_set_state(t_s_philo *philo, t_e_philo_state state)
{
	if (philo == NULL || state == E_PHILO_STATE_SIZE)
		return (EXIT_FAILURE);
	philo->state = state;
	message_bus_send(philo->id, philo->state);
	return (EXIT_SUCCESS);
}
