/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bus_send.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:34:37 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 14:27:03 by emcnab           ###   ########.fr       */
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

static void	message_bus_incr_head(t_s_message_bus *message_bus)
{
	pthread_mutex_lock(&message_bus->lock_head);
	if (message_bus->head < (message_bus->buffer_start + MESSAGE_BUS_SIZE - 1))
		message_bus->head++;
	else
		message_bus->head = message_bus->buffer_start;
	pthread_mutex_unlock(&message_bus->lock_head);
}

static void	message_bus_incr_size(t_s_message_bus *message_bus)
{
	pthread_mutex_lock(&message_bus->lock_size);
	message_bus->size++;
	pthread_mutex_unlock(&message_bus->lock_size);
}

/**
 * @brief Sends a message in a thread-safe way.
 *
 * Messages are sent to the message bus in a way that blocks writes but
 * minimises read blocks. Write block occurrs until message has been sent, but
 * read block only occurrs when retrieving and updating the last message.
 *
 * If the message bus is full, it will be automatically flushed. Updating the
 * message bus is done in such a way that if the flush function is called while
 * a new message is being added, but before the message values have been
 * updated, no invalid data will be read. This is because the message buffer
 * head is atomically incremented only once the message has been updated.
 *
 * @param id (size_t): Id of the philosopher sending the message.
 * @param state (t_e_philo_state): State of the philosopher sending the message.
 * Will condition the type of message to be displayed.
 *
 * @return (int32_t): EXIT_SUCCESS.
 */
// TODO: implement message bus freeze as soon as a philo dies (necessary ?)
// WARNING: still needs to receive last death message
int32_t	message_bus_send(int64_t time, int32_t id, t_e_philo_state state)
{
	t_s_message_bus	*message_bus;
	t_s_message		*tail;
	t_s_message		*head;

	message_bus = message_bus_get();
	pthread_mutex_lock(&message_bus->lock_write);
	tail = message_bus_get_tail();
	head = message_bus_get_head();
	if (message_bus_get_size() > 0 && head == tail)
		message_bus_flush();
	head->time = time - table_get()->time_start;
	head->id = id;
	head->state = state;
	message_bus_incr_head(message_bus);
	message_bus_incr_size(message_bus);
	pthread_mutex_unlock(&message_bus->lock_write);
	return (EXIT_SUCCESS);
}
