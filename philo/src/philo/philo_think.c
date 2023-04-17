/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:35:09 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 12:14:18 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_think.h"

#include <stdlib.h>
#include <sys/time.h>

#include "table.h"
#include "table_request.h"
#include "philo_set_state.h"

int32_t	philo_think(t_s_philo *philo)
{
	struct timeval	time;
	int64_t			time_delta;

	if (philo == NULL)
		return (EXIT_FAILURE);
	if (gettimeofday(&time, NULL) != EXIT_SUCCESS)
		return ((void)philo_set_state(philo, STATE_ERROR), EXIT_FAILURE);
	time_delta = time.tv_usec - philo->time_last_meal;
	if (time_delta >= table_get()->args->time_death)
		return ((void)philo_set_state(philo, STATE_DEAD), EXIT_FAILURE);
	if (table_request(philo) == true)
		return (philo_set_state(philo, STATE_PICK_FORK));
	return (EXIT_SUCCESS);
}
