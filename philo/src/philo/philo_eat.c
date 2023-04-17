/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:46:41 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 18:21:12 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_eat.h"

#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

#include "e_philo_state.h"
#include "table.h"
#include "message_bus_send.h"
#include "philo_set_state.h"
#include "time_millis.h"
#include "error_philo.h"

int32_t	philo_eat(t_s_philo *philo)
{
	t_s_table	*table;
	int64_t		time_curr;
	int64_t		time_delta;

	if (philo == NULL)
		return (EXIT_FAILURE);
	table = table_get();
	if (time_millis(&time_curr) != EXIT_SUCCESS)
		return (error_philo(philo, STATE_ERROR, -1));
	time_delta = time_curr - philo->time_last_meal;
	if (time_delta >= table->args->time_death)
		return (error_philo(philo, STATE_DEAD, time_curr));
	if (time_delta < table->args->time_eat)
		return (EXIT_SUCCESS);
	pthread_mutex_unlock(&philo->fork_right);
	pthread_mutex_unlock(&philo->fork_left);
	philo->meals++;
	philo->time_last_meal = time_curr;
	philo->owner = false;
	return (philo_set_state(philo, STATE_SLEEPING, time_curr));
}
