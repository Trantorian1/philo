/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:46:41 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 12:13:12 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_eat.h"

#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>
#include <pthread.h>

#include "table.h"
#include "message_bus_send.h"
#include "philo_set_state.h"

int32_t	philo_eat(t_s_philo *philo)
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
	if (time_delta < table_get()->args->time_eat)
		return (EXIT_SUCCESS);
	pthread_mutex_unlock(&philo->fork_right);
	pthread_mutex_unlock(&philo->fork_left);
	return (philo_set_state(philo, STATE_SLEEPING));
}
