/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_request.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:43:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 11:45:57 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_request.h"

#include <pthread.h>

#include "monitor_get.h"
#include "monitor_get_ticket.h"

static bool	check_ressources(t_s_monitor *monitor)
{
	pthread_mutex_lock(&monitor->lock_ressources);
	if (monitor->ressources < 2)
	{
		pthread_mutex_unlock(&monitor->lock_ressources);
		return (false);
	}
	monitor->ressources -= 2;
	pthread_mutex_unlock(&monitor->lock_ressources);
	return (true);
}

static void	update_philo(t_s_philo *philo)
{
	pthread_mutex_lock(&philo->fork_left);
	pthread_mutex_lock(&philo->fork_right);
}

bool	monitor_request(t_s_philo *philo)
{
	t_s_monitor	*monitor;

	monitor = monitor_get();
	pthread_mutex_lock(&monitor->lock_next);
	if (philo->ticket != monitor->ticket_next)
	{
		pthread_mutex_unlock(&monitor->lock_next);
		return (false);
	}
	monitor->ticket_next += check_ressources(monitor);
	pthread_mutex_unlock(&monitor->lock_next);
	update_philo(philo);
	return (true);
}
