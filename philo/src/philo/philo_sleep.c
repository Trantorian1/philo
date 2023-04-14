/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:30:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 18:36:56 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sleep.h"

#include <stdlib.h>
#include <sys/time.h>

#include "table.h"
#include "philo_set_state.h"

int32_t	philo_sleep(t_s_philo *philo)
{
	struct timeval	time;
	uint64_t		time_delta;

	if (philo == NULL)
		return (EXIT_FAILURE);
	if (gettimeofday(&time, NULL) != EXIT_SUCCESS)
		return ((void)philo_set_state(philo, STATE_ERROR), EXIT_FAILURE);
	time_delta = (uint64_t)time.tv_usec - philo->time_last_meal;
	if (time_delta >= table_get()->args->time_death)
		return (philo_set_state(philo, STATE_DEAD));
	if (time_delta < table_get()->args->time_sleep)
		return (EXIT_SUCCESS);
	return (philo_set_state(philo, STATE_THINKING));
}
