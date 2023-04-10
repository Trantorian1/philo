/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:20:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 15:14:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_create.h"
#include "e_error_code.h"
#include "error_bus.h"
#include "error_bus_set.h"
#include "s_error_bus.h"

#include <pthread.h>
#include <stdlib.h>

// TODO: implement synchronisation across threads
static void	*loop(void *data)
{
	t_s_philo	*philo;

	if (data == NULL)
		return (NULL);
	philo = (t_s_philo *)data;
	return (philo->runner(philo));
}

static void	*philo_error(t_s_philo *philo)
{
	t_s_error_bus	*bus;

	bus = error_bus();
	if (bus != NULL)
		error_bus_set(ERROR_CREATE);
	return (NULL);
}

t_s_philo	*philo_create(
	t_s_philo *philo,
	t_s_promise *promise,
	t_f_runner *runner)
{
	philo->state = WAITING;
	philo->promise = promise;
	philo->runner = runner;
	if (pthread_create(&philo->thread, NULL, &loop, philo) != EXIT_SUCCESS)
		return (philo_error(philo));
	pthread_detach(philo->thread);
	return (philo);
}
