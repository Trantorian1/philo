/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_get_ticket.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:40:28 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 11:08:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_get_ticket.h"

#include <pthread.h>

#include "monitor_get.h"

int32_t	monitor_get_ticket(void)
{
	t_s_monitor	*monitor;
	int32_t		ticket;

	monitor = monitor_get();
	pthread_mutex_lock(&monitor->lock_curr);
	ticket = monitor->ticket_curr++;
	pthread_mutex_unlock(&monitor->lock_curr);
	return (ticket);
}
