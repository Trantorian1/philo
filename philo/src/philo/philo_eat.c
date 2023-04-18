/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:46:41 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/18 10:39:30 by emcnab           ###   ########.fr       */
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

static void	restore_cutlerry(t_s_philo *philo)
{
	pthread_mutex_unlock(&philo->fork_right);
	pthread_mutex_unlock(&philo->fork_left);
}

static void	philo_update(t_s_philo *philo, int64_t time_curr)
{
	pthread_mutex_lock(&philo->lock_attr);
	philo->meals++;
	philo->time_last_meal = time_curr;
	philo->ownership = false;
	pthread_mutex_unlock(&philo->lock_attr);
}

int32_t	philo_eat(t_s_philo *philo)
{
	t_s_table	*table;
	int64_t		time_curr;
	int64_t		time_delta;

	if (philo == NULL)
		return (EXIT_FAILURE);
	table = table_get();
	if (time_millis(&time_curr) != EXIT_SUCCESS)
	{
		restore_cutlerry(philo);
		return (error_philo(philo, STATE_ERROR, -1));
	}
	time_delta = time_curr - philo->time_last_meal;
	if (time_delta >= table->args->time_death)
	{
		restore_cutlerry(philo);
		return (error_philo(philo, STATE_DEAD, time_curr));
	}
	if (time_delta < table->args->time_eat)
		return (EXIT_SUCCESS);
	restore_cutlerry(philo);
	philo_update(philo, time_curr);
	return (philo_set_state(philo, STATE_SLEEPING, time_curr));
}
