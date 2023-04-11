/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bus_get_tail.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:07:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 17:20:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_bus_get_tail.h"

#include "message_bus_get.h"

t_s_message	*message_bus_get_tail(void)
{
	t_s_message_bus	*message_bus;
	t_s_message		*tail;

	message_bus = message_bus_get();
	pthread_mutex_lock(&message_bus->lock_tail);
	tail = message_bus->tail;
	pthread_mutex_unlock(&message_bus->lock_tail);
	return (tail);
}
