/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:30:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 16:05:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sleep.h"

#include <stdlib.h>

#include "e_philo_state.h"
#include "error_philo.h"
#include "table.h"
#include "philo_set_state.h"
#include "time_millis.h"

int32_t	philo_sleep(t_s_philo *philo)
{
	int64_t	time_curr;
	int64_t	time_delta;

	if (philo == NULL)
		return (EXIT_FAILURE);
	if (time_millis(&time_curr) != EXIT_SUCCESS)
		return (error_philo(philo, STATE_ERROR, -1));
	time_delta = time_curr - philo->time_last_meal;
	if (time_delta >= table_get()->args->time_death)
		return (error_philo(philo, STATE_ERROR, time_curr));
	if (time_delta < table_get()->args->time_sleep)
		return (EXIT_SUCCESS);
	return (philo_set_state(philo, STATE_THINKING, time_curr));
}
