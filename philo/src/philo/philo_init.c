/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:20:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 12:13:35 by emcnab           ###   ########.fr       */
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
#include "table.h"

static int32_t	philo_update_time_last_meal(t_s_philo *philo)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != EXIT_SUCCESS)
	{
		philo->state = STATE_ERROR;
		return (EXIT_FAILURE);
	}
	philo->time_last_meal = time.tv_usec;
	return (EXIT_SUCCESS);
}

static void	*loop(void *data)
{
	t_s_philo	*philo;
	t_s_table	*table;

	if (data == NULL)
		return (NULL);
	philo = (t_s_philo *)data;
	table = table_get();
	while (table->game_state == IDLE)
		continue ;
	philo_set_state(philo, STATE_THINKING);
	philo_update_time_last_meal(philo);
	return (philo->runner(philo));
}

int32_t	philo_init(t_s_philo *philo, int32_t id, t_f_runner *runner)
{
	if (philo == NULL || runner == NULL)
		return (EXIT_FAILURE);
	philo->id = id;
	philo->time_last_meal = 0;
	philo->state = STATE_WAITING;
	philo->runner = runner;
	if (pthread_create(&philo->thread, NULL, &loop, philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&philo->lock_state, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
