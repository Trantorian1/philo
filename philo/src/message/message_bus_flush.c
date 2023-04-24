/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bus_flush.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:45:48 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/24 15:13:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_bus_flush.h"

#include <stdlib.h>

#include "message_bus_get.h"
#include "message_bus_get_tail.h"
#include "message_bus_get_head.h"
#include "message_print.h"

static t_s_message	*message_bus_incr_head(t_s_message_bus *message_bus)
{
	t_s_message	*message;

	pthread_mutex_lock(&message_bus->lock_head);
	if (message_bus->head < (message_bus->buffer_start + MESSAGE_BUS_SIZE - 1))
		message_bus->head++;
	else
		message_bus->head = message_bus->buffer_start;
	message = message_bus->head;
	pthread_mutex_unlock(&message_bus->lock_head);
	return (message);
}

static void	message_bus_update(t_s_message_bus *message_bus)
{
	pthread_mutex_lock(&message_bus->lock_tail);
	message_bus->tail = message_bus_incr_head(message_bus);
	pthread_mutex_unlock(&message_bus->lock_tail);
}

static void	message_bus_flush_iterative(
	t_s_message *tail,
	t_s_message *head)
{
	t_s_message	*cursor;

	cursor = tail;
	while (cursor < head)
	{
		message_print(cursor);
		cursor++;
	}
}

static void	message_bus_flush_circular(
	t_s_message_bus *message_bus,
	t_s_message *tail,
	t_s_message *head)
{
	t_s_message	*cursor;

	cursor = tail;
	while (cursor < (message_bus->buffer_start + MESSAGE_BUS_SIZE))
	{
		message_print(cursor);
		cursor++;
	}
	cursor = message_bus->buffer_start;
	while (cursor < head)
	{
		message_print(cursor);
		cursor++;
	}
}

/**
 * @brief Flushes the message bus in a thread-safe way.
 *
 * Flushes the message bus. Flushing is independant from writing, so this can be
 * performed as other threads write to the bus. Writing will only be locked for
 * the time it takes to retrieve the head of the buffer. This supposes that
 * other threads will not have time to overwrite pervious messages in the bus
 * as it is being flushed. For this reason, a safety threshold is set in
 * message_bus_send which flushes the buffer before it has been completly
 * filled, avoiding overwrites.
 *
 * @warning Due to the independant nature of message_bus_flush and
 * message_bus_send, it is possible for some messages to be missed during 
 * flushing. As a precaution, message_bus_flush should be called one last time
 * once all messaging threads have been joined.
 *
 * @return (int32_t): EXIT_SUCCESS
 */
int32_t	message_bus_flush(void)
{
	t_s_message_bus	*message_bus;
	t_s_message		*tail;
	t_s_message		*head;

	message_bus = message_bus_get();
	pthread_mutex_lock(&message_bus->lock_write);
	tail = message_bus_get_tail();
	head = message_bus_get_head();
	if (message_bus->size == 0)
	{
		pthread_mutex_unlock(&message_bus->lock_write);
		return (EXIT_SUCCESS);
	}
	message_bus->size = 0;
	message_bus_update(message_bus);
	pthread_mutex_unlock(&message_bus->lock_write);
	if (tail < head)
		message_bus_flush_iterative(tail, head);
	else
		message_bus_flush_circular(message_bus, tail, head);
	return (EXIT_SUCCESS);
}
