/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_restore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:33:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 11:50:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_restore.h"

#include "monitor_get.h"

static void	update_philo_ticket(t_s_monitor *monitor, t_s_philo *philo)
{
	pthread_mutex_lock(&monitor->lock_curr);
	philo->ticket = --monitor->ticket_curr;
	pthread_mutex_unlock(&monitor->lock_next);
}

static void	update_philo_forks(t_s_philo *philo)
{
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(&philo->fork_right);
}

void	monitor_restore(t_s_philo *philo)
{
	t_s_monitor	*monitor;

	monitor = monitor_get();
	pthread_mutex_lock(&monitor->lock_ressources);
	monitor->ressources += 2;
	update_philo_ticket(monitor, philo);
	pthread_mutex_unlock(&monitor->lock_ressources);
	update_philo_forks(philo);
}
