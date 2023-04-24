/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bus_send.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:34:37 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/24 15:18:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_bus_send.h"

#include <stdlib.h>

#include "message_bus_get.h"
#include "message_bus_flush.h"
#include "message_bus_get_head.h"
#include "message_bus_get_size.h"
#include "message_bus_get_tail.h"
#include "table.h"
#include "table_get_state.h"

#define FLUSH_THRESHOLD 32

static t_s_message	*message_bus_incr_head(t_s_message_bus *message_bus)
{
	t_s_message	*head;

	pthread_mutex_lock(&message_bus->lock_head);
	if (message_bus->head < (message_bus->buffer_start + MESSAGE_BUS_SIZE - 1))
		message_bus->head++;
	else
		message_bus->head = message_bus->buffer_start;
	head = message_bus->head;
	pthread_mutex_unlock(&message_bus->lock_head);
	return (head);
}

static size_t	message_bus_incr_size(t_s_message_bus *message_bus)
{
	size_t	size_buffer;

	pthread_mutex_lock(&message_bus->lock_size);
	size_buffer = message_bus->size++;
	pthread_mutex_unlock(&message_bus->lock_size);
	return (size_buffer);
}

/**
 * @brief Sends a message in a thread-safe way.
 *
 * Messages are sent to the message bus in a way that blocks writes but
 * minimises read blocks. Writing is blocked for the duration of the message
 * send, but reading is only blocked for the time it takes to retrieve and
 * update the head.
 *
 * If the message bus is full, it will be automatically flushed. A security
 * threashold is set to avoid buffer overwrites, so the message bus may flush
 * early. This avoids message_bus_flush reading any data as it is being updated
 * by message_bus_send.
 *
 * Updating the message bus is done in such a way that if the flush function is
 * called while a new message is being added, but before the message values have
 * been updated, no invalid data will be read. This is because the message
 * buffer head is atomically incremented only once the message has been updated.
 *
 * @param id (size_t): Id of the philosopher sending the message.
 * @param state (t_e_philo_state): State of the philosopher sending the message.
 * Will condition the type of message to be displayed.
 *
 * @return (int32_t): EXIT_SUCCESS.
 */
int32_t	message_bus_send(int64_t time, int32_t id, t_e_philo_state state)
{
	t_s_message_bus	*message_bus;
	t_s_message		*tail;
	t_s_message		*head;
	size_t			size;

	message_bus = message_bus_get();
	pthread_mutex_lock(&message_bus->lock_write);
	tail = message_bus_get_tail();
	head = message_bus_get_head();
	head->time = time - table_get()->time_start;
	head->id = id;
	head->state = state;
	size = message_bus_incr_size(message_bus);
	head = message_bus_incr_head(message_bus);
	pthread_mutex_unlock(&message_bus->lock_write);
	if (head > tail)
		return (EXIT_SUCCESS);
	if (size > 0 && (tail - head) <= FLUSH_THRESHOLD)
		message_bus_flush();
	return (EXIT_SUCCESS);
}
