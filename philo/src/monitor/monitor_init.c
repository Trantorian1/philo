/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:28:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 11:17:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_init.h"

#include <pthread.h>
#include <stdlib.h>

#include "monitor_get.h"

typedef enum e_error_local
{
	ERROR_NONE,
	ERROR_LOCK_NEXT,
	ERROR_LOCK_CURR,
	ERROR_LOCK_RESSOURCES,
	E_ERROR_LOCAL_SIZE
}	t_e_error_local;

static int32_t	error_free(t_s_monitor *monitor, t_e_error_local error_code)
{
	if (error_code == ERROR_LOCK_CURR || error_code == ERROR_LOCK_RESSOURCES)
		pthread_mutex_destroy(&monitor->lock_next);
	if (error_code == ERROR_LOCK_RESSOURCES)
		pthread_mutex_destroy(&monitor->lock_curr);
	return (EXIT_FAILURE);
}

int32_t	monitor_init(t_s_args *args)
{
	t_s_monitor	*monitor;

	monitor = monitor_get();
	monitor->ticket_next = 0;
	monitor->ticket_curr = 0;
	monitor->ressources = args->philo_count;
	if (pthread_mutex_init(&monitor->lock_next, NULL) == EXIT_FAILURE)
		return (error_free(monitor, ERROR_LOCK_NEXT));
	if (pthread_mutex_init(&monitor->lock_curr, NULL) == EXIT_FAILURE)
		return (error_free(monitor, ERROR_LOCK_CURR));
	if (pthread_mutex_init(&monitor->lock_ressources, NULL) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
