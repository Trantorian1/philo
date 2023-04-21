/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pickup_fork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:04:25 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 11:48:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_pickup_fork.h"

#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

#include "e_philo_state.h"
#include "message_bus_send.h"
#include "philo_set_state.h"
#include "philo_set_time_last_meal.h"
#include "time_millis.h"
#include "error_philo.h"

int32_t	philo_pickup_fork(t_s_philo *philo)
{
	int64_t	time_curr;

	if (philo == NULL)
		return (EXIT_FAILURE);
	pthread_mutex_lock(&philo->fork_left);
	pthread_mutex_lock(&philo->fork_right);
	if (time_millis(&time_curr) != EXIT_SUCCESS)
		return (error_philo(philo, STATE_DEAD, -1));
	philo_set_time_last_meal(philo, time_curr);
	return (philo_set_state(philo, STATE_EATING, philo->time_last_meal));
}
