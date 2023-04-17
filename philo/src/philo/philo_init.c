/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:20:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 18:16:12 by emcnab           ###   ########.fr       */
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
#include "time_millis.h"
#include "table.h"

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
	if (time_millis(&philo->time_last_meal) != EXIT_SUCCESS)
		return ((void)philo_set_state(philo, STATE_ERROR, -1), NULL);
	philo_set_state(philo, STATE_THINKING, philo->time_last_meal);
	return (philo->runner(philo));
}

int32_t	philo_init(t_s_philo *philo, int32_t id, t_f_runner *runner)
{
	if (philo == NULL || runner == NULL)
		return (EXIT_FAILURE);
	philo->id = id;
	philo->meals = 0;
	philo->owner = false;
	philo->time_last_meal = 0;
	philo->state = STATE_WAITING;
	philo->runner = runner;
	if (pthread_create(&philo->thread, NULL, &loop, philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&philo->lock_state, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
