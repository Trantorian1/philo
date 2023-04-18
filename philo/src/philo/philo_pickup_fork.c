/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pickup_fork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:04:25 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/18 08:38:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_pickup_fork.h"

#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

#include "e_philo_state.h"
#include "message_bus_send.h"
#include "philo_set_state.h"
#include "time_millis.h"
#include "error_philo.h"

int32_t	philo_pickup_fork(t_s_philo *philo)
{
	if (philo == NULL)
		return (EXIT_FAILURE);
	pthread_mutex_lock(&philo->fork_left);
	pthread_mutex_lock(&philo->fork_right);
	if (time_millis(&philo->time_last_meal) != EXIT_SUCCESS)
		return (error_philo(philo, STATE_DEAD, -1));
	return (philo_set_state(philo, STATE_EATING, philo->time_last_meal));
}
