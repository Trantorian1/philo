/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:20:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/12 10:35:56 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_init.h"

#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>

#include "e_error_code.h"
#include "e_game_state.h"
#include "error_bus.h"
#include "error_bus_set.h"
#include "s_error_bus.h"
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
	return (philo->runner(philo));
}

int32_t	philo_init(
	t_s_philo *philo,
	size_t id,
	t_f_runner *runner)
{
	if (philo == NULL || runner == NULL)
		return (EXIT_FAILURE);
	philo->id = id;
	philo->state = STATE_WAITING;
	philo->runner = runner;
	if (pthread_create(&philo->thread, NULL, &loop, philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
