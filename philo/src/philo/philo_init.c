/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:20:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 14:07:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>

#include "e_error_code.h"
#include "e_game_state.h"
#include "e_philo_state.h"
#include "philo_set_state.h"
#include "philo_set_time_last_meal.h"
#include "philo_set_ownership.h"
#include "table_get_state.h"
#include "time_millis.h"
#include "table.h"

static void	*loop(void *data)
{
	t_s_philo	*philo;
	int64_t		time_start;

	if (data == NULL)
		return (NULL);
	philo = (t_s_philo *)data;
	while (table_get_state() == IDLE)
		continue ;
	time_start = table_get()->time_start;
	philo_set_time_last_meal(philo, time_start);
	if (philo->id % 2 == 1)
	{
		philo_set_state(philo, STATE_PICK_FORK, time_start);
		philo_set_ownership(philo, true);
		pthread_mutex_lock(&philo->fork_left);
		pthread_mutex_lock(&philo->fork_right);
		philo_set_state(philo, STATE_EATING, time_start);
	}
	else
		philo_set_state(philo, STATE_THINKING, time_start);
	return (philo->runner(philo));
}

int32_t	philo_init(t_s_philo *philo, int32_t id, t_f_runner *runner)
{
	if (philo == NULL || runner == NULL)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&philo->lock_state, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&philo->lock_attr, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	pthread_mutex_lock(&philo->lock_attr);
	philo->id = id;
	philo->meals = 0;
	philo->ownership = false;
	philo->time_last_meal = 0;
	philo->state = STATE_WAITING;
	philo->runner = runner;
	pthread_mutex_unlock(&philo->lock_attr);
	if (pthread_create(&philo->thread, NULL, &loop, philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
